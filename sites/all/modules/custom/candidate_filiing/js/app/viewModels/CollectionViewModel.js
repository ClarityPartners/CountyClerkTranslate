var CollectionViewModel = function CollectionViewModel(baseUrl, baseElement, query, queryCallback, pagination) {
	this.baseUrl = ko.observable(baseUrl);
	this.baseElement = ko.observable(baseElement);
	this.query = ko.observable(query);

	this.item = ko.observableArray([]);
	this.count = ko.observable(0);

	this.loaded = ko.observable(false);
	this.failed = ko.observable(false);
	this.failedMessage = ko.observable("");
	this.refreshing = ko.observable(false);

	this.fnQueryCallback = (queryCallback && typeof queryCallback === "function" ? queryCallback : function() {});

	this.pagination = ko.observable(!!pagination);
	this.page = ko.observable(0);
	this.itemsPerPage = ko.observable(55); // fallback value (can be overridden by data received)
	/*this.maxPages = ko.computed(function() {
		if (this.count && this.count() <= 0) return 0;

		return this.count() / this.itemsPerPage();
	});*/

	this.getData = function (fnCallback) {
		var self = this;

		this.evaluatePagination();

		jQuery.getJSON(this.baseUrl(), jQuery.extend({}, this.query(), { _: new Date().getTime() }), function (data) {
			if (data && data.Status) {
				self.fnQueryCallback(data);

				if (data[self.baseElement()]) {
					ko.mapping.fromJS(data[self.baseElement()], {}, self.item);
				}

				if (data.count) {
					self.count(data.count);
				} else {
					if (self.item && self.item() && self.item().length) {
						self.count(self.item().length);
					} else {
						self.count(0);
					}
				}

				if (data.itemsPerPage) {
					self.itemsPerPage(data.itemsPerPage);
				}

				if (fnCallback && typeof fnCallback === "function") {
					fnCallback();
				}
			} else {
				self.page(0);
				self.count(0);
				self.item({});

				if (data.Message) {
					self.failedMessage(data.Message);
				}

				self.failed(true);
			}
		}).fail(function (jqXHR, status, error) {
			self.failed(true);
			self.fnQueryCallback();
		}).always(function () {
			self.loaded(true);
			self.refreshing(false);
		});
	};

	this.fetchWithQueryAndCallback = function (fnCallback, query) {
		this.loaded(false);
		this.failed(false);
		this.refreshing(true);

		if (query) {
			this.query(query);
		}

		this.getData(fnCallback);
	};

	this.fetchWithQuery = function (query) {
		this.page(0);
		this.fetchWithQueryAndCallback(query);
	};

	this.fetch = function () {
		this.page(0);
		this.fetchWithQueryAndCallback();
	};

	this.evaluatePagination = function() {
		if (this.pagination && this.pagination() && this.query) {
			this.refreshing(true);

			if (!this.query())
				this.query({});

			var paginationQuery = this.query();
			paginationQuery.skip = this.page() * this.itemsPerPage();
			paginationQuery.take = this.itemsPerPage(); // dynamic

			this.query(paginationQuery);
		}
	};

	//this.scrollToTop = function() {
		// scroll top top of the page / view
		//window.location.href = "#top";
	//};

	this.pageNext = function () {
		if (this.page() < Math.floor(this.count() / this.itemsPerPage())) {
			this.page(this.page() + 1);

			//this.scrollToTop();

			this.getData();
		}
	};

	this.pagePrevious = function () {
		if (this.page() > 0) {
			this.page(this.page() - 1);

			//this.scrollToTop();

			this.getData();
		}
	};

	this.resetFailed = function() {
		if (this.refreshing && !this.refreshing()) {
			this.failed(false);
			this.failedMessage("");
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
