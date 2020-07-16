<?php
$text_content = variable_get('text_polling_places', '');
?>

<script type="text/javascript">
	jQuery('h1.page-header').hide();
	jQuery('article.node-service').hide();

	if (typeof _viewModels === "undefined" || !_viewModels) {
		var _viewModels = {isRoot: ko.observable(true)};
	}

	var inputViewModelSettings = {
		electionUrl: "/api/Election/GetCurrentElectionForAPI",
		electionsUrl: "/api/Election/GetAll",
		baseUrl: "/api/PollingPlace/GetPollingPlaces",
		townshipOptionsUrl: "/api/Township/GetAll",
		townshipAll: "",
		electionCode: "0",
		dropDownOptions: []
	};

	jQuery(document).ready(function () {
		_viewModels.Elections = new ElectionDropDownViewModel(inputViewModelSettings.electionsUrl, "pollingPlaces");

		_viewModels.pollingPlaces = new ElectionCollectionViewModel(
			inputViewModelSettings.electionUrl,
			inputViewModelSettings.townshipOptionsUrl,
			"Townships",
			{"electionCode": inputViewModelSettings.electionCode},
			function (result, inputQuery) {
				var pollingPlaceQuery = _viewModels.pollingPlaces.PollingPlaces.query();
				pollingPlaceQuery.electionCode = result.ElectionCode;

				pollingPlaceQuery.code = inputViewModelSettings.townshipAll;
				_viewModels.pollingPlaces.PollingPlaces.query(pollingPlaceQuery);

				_viewModels.pollingPlaces.PollingPlaces.fetch();

				return true;
			},
			_viewModels.Elections.mapElectionCodeCallback
		);

		_viewModels.pollingPlaces.PollingPlaces = new CollectionViewModel(inputViewModelSettings.baseUrl, "PollingPlaces", {
			"electionCode": inputViewModelSettings.electionCode,
			"code": inputViewModelSettings.townshipAll
		});

		ko.applyBindings(_viewModels);
	});
</script>

<!-- ko with: _viewModels.pollingPlaces -->
<!-- ko if: loaded -->

<!-- ko with: PollingPlaces -->
<h3 data-bind="css: { 'text-muted' : !$parent.loaded() || refreshing() }">
			<span class="h2">
				<strong>
					<span style="display:block">Polling Places</span>
					<span data-bind="text: $parent.item().ElectionDate"></span>
					<span	data-bind="text: $parent.item().Description"></span> Election
				</strong>
			</span>
	<img src="/sites/all/modules/custom/candidate_filiing/images/spinner.gif" alt="Loading"
	     data-bind="visible: !$parent.loaded() || refreshing()"/>
</h3>
<!-- /ko -->

<div class="container app">
	<?php echo $text_content; ?>
</div>
<div class="candidate-bar" data-bind="visible: item().IsPrimary">
	<div class="candidate-info container view-all">
		<div class="form-item form-item-status-filter polling form-type-select form-group">
			<!-- ko with: Townships -->
			<label class="control-label" for="edit-status-filter">Township</label>
			<select class="form-control form-select" id="edit-status-filter" name="edit-status-filter"
			        data-bind="options: item(), optionsCaption: 'All', optionsText: 'Name', optionsValue: 'Code', value: _viewModels.pollingPlaces.PollingPlaces.query().code, valueAllowUnset: true"></select>
			<!-- /ko -->
		</div>
		<!-- ko with: PollingPlaces -->
		<button type="button" id="edit-status-submit" name="status_submit" value="Apply"
		        class="btn btn-info form-submit" data-bind="click: fetch">Apply
		</button>
		<!-- /ko -->
	</div>
</div>

<!-- /ko -->

<!-- ko with: PollingPlaces -->
<!-- ko if: loaded -->

<table class="table table-bordered table-striped early-voting" style="display: none;"
       data-bind="visible: item().length > 0">
	<thead>
	<tr>
		<th data-bind="sort: { arr: item, prop: 'Name()' }">Location</th>
		<th data-bind="sort: { arr: item, prop: 'Address1()' }">Address</th>
		<th data-bind="sort: { arr: item, prop: 'HandicapAccessible()' }">Accessible</th>
		<th data-bind="sort: { arr: item, prop: 'TownshipFullName()' }">Township &amp; Precinct</th>
	</tr>
	</thead>
	<tbody data-bind="foreach: item">
	<tr>
		<td data-bind="text: Name"></td>
		<td>
			<a data-bind="attr: { href: 'https://maps.google.com?q=' + encodeURIComponent( (Address1 && Address1() ? (Address1()) : '') + (CityStateZip && CityStateZip() ? ', ' + CityStateZip() : '') ) }"
			   target="_blank">
				<div data-bind="text: Address1"></div>
				<div data-bind="text: CityStateZip"></div>
			</a>
		</td>
		<td data-bind="text: HandicapAccessible" style="text-align:center"></td>
		<td>
			<div data-bind="foreach: TownshipPrecincts">
				<div data-bind="text: $data"></div>
			</div>
		</td>
	</tr>
	</tbody>
</table>

<!-- No Results -->
<p class="alert alert-info" style="display: none; margin-bottom: 40px;"
   data-bind="visible: loaded() && !failed() && item().length <= 0">
	<!--<span class="glyphicon glyphicon-info-sign" aria-hidden="true"></span>-->
	<span class="sr-only">No Results:</span>
	No data is currently available
</p>

<!-- Error -->
<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed()">
	<!--<span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>-->
	<span class="sr-only">Error:</span>
	An unexpected problem has occurred while retrieving data. <span
			data-bind="visible: failedMessage && failedMessage(), text: failedMessage"></span>
</p>

<!-- /ko -->
<!-- /ko -->

<!-- Outer Error -->
<p class="alert alert-danger" style="display: none; margin-bottom: 40px;"
   data-bind="visible: loaded() && failed() && failedMessage && failedMessage()">
	<span data-bind="text: failedMessage"></span>
</p>

<!-- /ko -->
<!-- /ko -->

<script type="text/javascript">
	jQuery(document).ready(function () {
		_viewModels.Elections.fetch();
	});
</script>
