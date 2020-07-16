<?php
$text_content = variable_get('text_total_gv', '');
?>

<style type="text/css">
	.active-cursor {
		cursor: pointer;
	}

	.noselect {
		-webkit-touch-callout: none; /* iOS Safari */
		-webkit-user-select: none; /* Safari */
		-khtml-user-select: none; /* Konqueror HTML */
		-moz-user-select: none; /* Firefox */
		-ms-user-select: none; /* Internet Explorer/Edge */
		user-select: none;
		/* Non-prefixed version, currently
										 supported by Chrome and Opera */
	}
</style>

<script type="text/javascript">
	jQuery('h1.page-header').hide();
	jQuery('article.node-service').hide();

	if (typeof _viewModels === "undefined" || !_viewModels) {
		var _viewModels = {isRoot: ko.observable(true)};
	}

	var inputViewModelSettings = {
		electionUrl: "/api/Election/GetCurrentElectionForAPI",
		electionsUrl: "/api/Election/GetAll",
		locationOptionsUrl: "/api/Election/GetGraceVotingLocationOptions",
		baseUrl: "/api/SpecialVoting/GetGraceVotingLocationTotal",
		electionCode: "0",
		locationId: "",
		votedOn: "",
		mapToVotedOn: function (result) {
			if (result && result.GracePeriodOpenDate && result.GracePeriodCloseDate) {
				var start = new Date(result.GracePeriodOpenDate());
				var future = new Date(result.GracePeriodCloseDate());
				var mil = 86400000; //24hr
				for (var i = start.getTime(); i <= future.getTime() + mil; i = i + mil) {
					var currentDate = new Date(i);
					_viewModels.votedOnDates.options.push({
						id: currentDate.toJSON(),
						value: DateTimeUtility(currentDate).asFriendlyDate()
					});
				}
			}
		}
	};

	jQuery(document).ready(function () {
		ko.options.deferUpdates = true;

		_viewModels.Elections = new ElectionDropDownViewModel(inputViewModelSettings.electionsUrl, "locationVotingTotals");

		_viewModels.locationVotingTotals = new ElectionCollectionViewModel(
			inputViewModelSettings.electionUrl,
			inputViewModelSettings.locationOptionsUrl,
			"VotingLocationOptions",
			{"electionCode": inputViewModelSettings.electionCode},
			function (result, inputQuery) {
				var locationVotingTotalsQuery = _viewModels.locationVotingTotals.LocationVotingTotals.query();
				if (ko.isObservable(locationVotingTotalsQuery.electionCode))
					locationVotingTotalsQuery.electionCode(result.ElectionCode());
				else
					locationVotingTotalsQuery.electionCode = result.ElectionCode;

				_viewModels.locationVotingTotals.LocationVotingTotals.query(locationVotingTotalsQuery);

				inputViewModelSettings.mapToVotedOn(result);

				return true;
			}
		);

		_viewModels.locationVotingTotals.locationVotingTotalSum = ko.observable(0);

		_viewModels.locationVotingTotals.LocationVotingTotals = new CollectionViewModel(inputViewModelSettings.baseUrl, "LocationVotingTotals", {
			"electionCode": inputViewModelSettings.electionCode,
			"locationId": inputViewModelSettings.locationId,
			"votedOn": inputViewModelSettings.votedOn
		}, function (data) {
			if (data && data.LocationVotingTotalSum) {
				_viewModels.locationVotingTotals.locationVotingTotalSum(data.LocationVotingTotalSum);
			} else {
				_viewModels.locationVotingTotals.locationVotingTotalSum(0);
			}
		}, true);

		_viewModels.votedOnDates = new DropDownViewModel([], "id", "value");

		ko.computed(function() {
			return ko.toJSON(_viewModels.locationVotingTotals.LocationVotingTotals.query);
		}).extend({ deferred: true }).subscribe(function() {
			// called whenever any of the properties of complexObject changes
			if (this && this.query && this.query() && this.query().electionCode) {
				_viewModels.Elections.mapElectionCodeCallback(undefined, this.query().electionCode());
				//debugger;
			}
		}, _viewModels.locationVotingTotals.LocationVotingTotals);

		_viewModels.locationVotingTotals.item.extend({ deferred: true }).subscribe(function(result) {
			if (_viewModels.locationVotingTotals.VotingLocationOptions.query().electionCode === result.ElectionCode())
				return;

			var locationOptionQuery = _viewModels.locationVotingTotals.VotingLocationOptions.query();
			var resultQuery = _viewModels.locationVotingTotals.LocationVotingTotals.query();
			if (ko.isObservable(locationOptionQuery.electionCode))
				locationOptionQuery.electionCode(result.ElectionCode());
			else
				locationOptionQuery.electionCode = result.ElectionCode();

			_viewModels.locationVotingTotals.VotingLocationOptions.query(locationOptionQuery);

			resultQuery.locationId = inputViewModelSettings.locationId;
			resultQuery.votedOn = inputViewModelSettings.votedOn;

			_viewModels.locationVotingTotals.LocationVotingTotals.query(resultQuery);

			_viewModels.votedOnDates.options.removeAll();

			inputViewModelSettings.mapToVotedOn(result);

			_viewModels.locationVotingTotals.VotingLocationOptions.fetch();

			return;
		});

		ko.applyBindings(_viewModels);
	});
</script>

<!-- ko with: _viewModels.locationVotingTotals -->
<!-- ko if: loaded -->
<h3 data-bind="css: { 'text-muted' : ((LocationVotingTotals.refreshing() && !LocationVotingTotals.loaded()) || LocationVotingTotals.refreshing()) }" style="line-height: 36px;">
		<span class="h2">
			<strong>
			<span style="display:block">Grace Period Voting Totals</span>
			<span data-bind="text: item().ElectionDate"></span>
			<span data-bind="text: item().Description"></span> Election
			</strong>
		</span>
	<img src="/sites/all/modules/custom/candidate_filiing/images/spinner.gif" alt="Loading"
	     data-bind="fadeVisible: (LocationVotingTotals.refreshing() && !LocationVotingTotals.loaded()) || LocationVotingTotals.refreshing()"/>
</h3>

<div class="container app">
	<?php echo $text_content; ?>
</div>
<div class="candidate-bar evlocations">
	<div class="candidate-info container">
		<div class="form-item form-item-status-filter form-type-select form-group">
			<!-- ko with: _viewModels.Elections -->
			<div class="evtotals-location">
				<label class="control-label" for="edit-election-filter">Election:</label>
				<select class="form-control form-select" id="edit-election-filter" name="edit-election-filter" data-bind="options: item, optionsText: 'ElectionDate', optionsValue: 'ElectionCode', value: _viewModels.locationVotingTotals.LocationVotingTotals.query().electionCode"></select>
			</div>
			<!-- /ko -->

			<!-- ko with: VotingLocationOptions -->
			<div class="evtotals-location">
				<label class="control-label" for="edit-status-filter-1">Location:</label>
				<select class="form-control form-select" id="edit-status-filter-1" name="edit-status-filter-1"
				        data-bind="options: item, optionsCaption: 'All Locations', optionsText: 'value', optionsValue: 'id', value: _viewModels.locationVotingTotals.LocationVotingTotals.query().locationId, valueAllowUnset: true"></select>
			</div>
			<!-- /ko -->

			<!-- ko with: _viewModels.votedOnDates -->
			<div class="evtotals-dates">
				<label class="control-label" for="edit-status-filter-2">Dates:</label>
				<select class="form-control form-select" id="edit-status-filter-2" name="edit-status-filter-2"
				        data-bind="options: options, optionsCaption: 'All Dates', optionsText: text, optionsValue: value, value: _viewModels.locationVotingTotals.LocationVotingTotals.query().votedOn, valueAllowUnset: true"></select>
			</div>
			<!-- /ko -->
		</div>
		<!-- ko with: LocationVotingTotals -->
		<button type="button" id="edit-status-submit" name="status_submit" value="Apply"
		        class="btn btn-info form-submit" data-bind="click: fetch">Get Totals
		</button>
		<!-- /ko -->
	</div>
</div>

<!-- ko with: LocationVotingTotals -->
<!-- ko if: loaded -->

<div class="pull-right evlocations" data-bind="visible: loaded() && !failed() && item().length > 0">
	<strong>Total Votes:</strong>
	<span data-bind="largeNumber: _viewModels.locationVotingTotals.locationVotingTotalSum"></span>
</div>

<table class="table table-bordered table-striped evlocations" style="display: none;"
       data-bind="visible: item().length > 0">
	<thead>
	<tr>
		<th>Date</th>
		<th>Location</th>
		<th style="text-align:center">Vote Count</th>
	</tr>
	</thead>
	<tbody data-bind="foreach: item">
	<tr>
		<td>
			<span data-bind="text: DateTimeUtility(VotedOn()).asFriendlyDate()"></span>
		</td>
		<td data-bind="text: LocationName"></td>
		<td data-bind="text: TotalVote" style="text-align:center"></td>
	</tr>
	</tbody>
</table>

<!-- No Results -->
<p class="alert alert-info" style="display: none; margin-bottom: 40px;"
   data-bind="visible: loaded() && !failed() && item().length <= 0">
	<span class="sr-only">No Results:</span>
	No results were currently found.
</p>

<!-- Error -->
<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed()">
	<span class="sr-only">Error:</span>
	Information could not be provided. <span
			data-bind="visible: failedMessage && failedMessage(), text: failedMessage"></span>
</p>

<div class="pull-right">
	<strong>Total Votes:</strong>
	<span data-bind="largeNumber: _viewModels.locationVotingTotals.locationVotingTotalSum"></span>
</div>

<!-- /ko -->

<!-- ko if: loaded() && item().length > 0 -->
<div class="text-center" style="display: none;" data-bind="visible: (loaded() && item().length > 0)">
	<ul class="pagination pagination-lg" style="margin-top: 10px;">
		<li class="active-cursor noselect" data-bind="css: { 'disabled' : page() === 0 }">
			<span aria-label="Previous" data-bind="click: pagePrevious">
				<span aria-hidden="true"><!--<span class="glyphicon glyphicon-chevron-left"></span>--> &laquo; Previous</span>
			</span>
		</li>
		<li class="disabled">
			<span>
				Page <span data-bind="text: (page() + 1)"></span> of <span
						data-bind="text: (Math.floor(count() / itemsPerPage()) + 1)"></span>
			</span>
		</li>
		<li class="active-cursor noselect" data-bind="css: { 'disabled' : ((page() + 1) * itemsPerPage()) >= count() }">
			<span aria-label="Next" data-bind="click: pageNext">
				<span aria-hidden="true">Next &raquo;
					<!--<span class="glyphicon glyphicon-chevron-right"></span>--></span>
			</span>
		</li>
	</ul>
</div>
<!-- /ko -->


<!-- /ko -->
<!-- /ko -->

<!-- /ko -->

<!-- /ko -->

<script type="text/javascript">
	jQuery(document).ready(function () {
		_viewModels.Elections.fetch();
	});
</script>
