var SingleViewModel = function SingleViewModel(baseUrl, baseElement, query, queryCallback) {
	this.baseUrl = ko.observable(baseUrl);
	this.baseElement = ko.observable(baseElement);
	this.query = ko.observable(query);
	this.id = ko.observable(0);

	this.item = ko.observable({});

	this.loaded = ko.observable(false);
	this.failed = ko.observable(false);
	this.failedMessage = ko.observable("");
	this.refreshing = ko.observable(false);

	this.fnQueryCallback = (queryCallback && typeof queryCallback === "function" ? queryCallback : function() {});

	this.getData = function (fnCallback) {
		var self = this;

		jQuery.getJSON(this.baseUrl(), jQuery.extend({}, this.query(), { _: new Date().getTime() }), function (data) {
			if (data && data.status) {
				self.fnQueryCallback(data);

				if (data.hasOwnProperty(self.baseElement()) && data[self.baseElement()]) {
					ko.mapping.fromJS(data[self.baseElement()], {}, self.item);
				}

				if (self.item && self.item() && self.item().id && self.item().id()) {
					self.id(self.item().id());
				}

				if (fnCallback && typeof fnCallback === "function") {
					fnCallback();
				}
			} else {
				self.item({});

				if (data.message) {
					self.failedMessage(data.message);
				}

				self.failed(true);
			}
		}).fail(function (jqXHR, status, error) {
			self.failed(true);
			self.id(0);
			self.fnQueryCallback();
		}).always(function () {
			self.loaded(true);
			self.refreshing(false);
		});
	};

	this.fetchRaw = function (fnCallback, query) {
		this.loaded(false);
		this.failed(false);
		this.failedMessage("");
		this.refreshing(true);

		if (query) {
			this.query(query);
		}

		this.getData(fnCallback);
	};

	this.fetch = function (id, fnCallback) {
		if (id) {
			this.fetchRaw(fnCallback, { id: id });
		} else {
			this.fetchRaw(fnCallback);
		}
	};

	this.init = function (baseUrl, query) {
		if (baseUrl) {
			this.baseUrl(baseUrl);
		}

		if (query) {
			this.query(query);
		}
	};
};