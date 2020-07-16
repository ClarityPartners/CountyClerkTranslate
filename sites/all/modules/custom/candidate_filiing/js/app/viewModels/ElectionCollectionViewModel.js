var ElectionCollectionViewModel = function ElectionCollectionViewModel(electionBaseUrl, collectionBaseUrl, collectionBaseElement, collectionQuery, performQueryCondition, postCollectionCallback) {
	return setObjectPropertyByName(
		jQuery.extend({},
			new CollectionViewModel(electionBaseUrl, "Election", {}),
			{
				fetch: function () {
					var self = this;
					this.getData(function () {
						if (self.item && self.item() && self.item().ElectionCode && self.item().ElectionCode()) {
							self[collectionBaseElement].query(jQuery.extend({},
								self[collectionBaseElement].query(),
								{ electionCode: self.item().ElectionCode() }));
						}

						if (typeof performQueryCondition === "undefined" || (typeof performQueryCondition !== "function" && !!performQueryCondition)) {
							self[collectionBaseElement].fetch();
						} else if (typeof performQueryCondition === "function") {
							if (self.item && self.item() && performQueryCondition(self.item(), self[collectionBaseElement].query)) {
								self[collectionBaseElement].fetch();
							} else {
								self[collectionBaseElement].loaded(true);
							}
						} else {
							self[collectionBaseElement].loaded(true);
						}
					});
				},
				item: ko.observable({})
			}
		),
		collectionBaseElement,
		new CollectionViewModel(collectionBaseUrl, collectionBaseElement, collectionQuery, postCollectionCallback));
};
