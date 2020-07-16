var ElectionDropDownViewModel = function ElectionDropDownViewModel(electionsUrl, collectionRootElement, postCollectionCallback, mapElectionCodeCallbackOverride) {
	return jQuery.extend({},
			new CollectionViewModel(electionsUrl, "Elections", {}, (typeof postCollectionCallback !== "undefined" && !!postCollectionCallback) ? postCollectionCallback : function() { if (!!collectionRootElement && !!_viewModels[collectionRootElement]) { _viewModels[collectionRootElement].fetch(); } }),
			{
				electionCodeToElement: function (code) {
					if (!code) {
						return {};
					}

					var electionsLength = _viewModels.Elections.item().length;
					for (var i = 0; i < electionsLength; i++) {

						if (_viewModels.Elections.item()[i].ElectionCode() === code) {
							return _viewModels.Elections.item()[i];
						}

					}

					return {};
				},
				mapElectionCodeCallback: (typeof mapElectionCodeCallbackOverride === "function" && !!mapElectionCodeCallbackOverride) ? mapElectionCodeCallbackOverride : function (result, overrideElectionCode, overrideCollectionRootElement) {
					var electionElement = _viewModels.Elections.electionCodeToElement(!!overrideElectionCode ? overrideElectionCode : this.query().electionCode);

					if (!!electionElement) {
						if (!!overrideCollectionRootElement && !!_viewModels[overrideCollectionRootElement]) {
							_viewModels[overrideCollectionRootElement].item(electionElement);
						} else if (!!collectionRootElement && !!_viewModels[collectionRootElement]) {
							_viewModels[collectionRootElement].item(electionElement);
						}
					}
				}
			}
		);
};