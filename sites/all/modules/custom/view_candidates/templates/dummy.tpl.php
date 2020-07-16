<?php
	$text_dumcontent = variable_get('text_dummy', '');
?>

<script type="text/javascript">
jQuery('h1.page-header').hide();
jQuery('article.node-service, article.node-page').hide();

if (typeof _viewModels === "undefined" || !_viewModels) {
	var _viewModels = { isRoot: ko.observable(true) };
}

var inputViewModelSettings = {
	electionUrl: "/api/Election/GetCurrentElectionForAPI",
	electionsUrl: "/api/Election/GetAll",
	baseUrl: "/api/Election/GetEarlyVotingLocationList",
	electionCode: "0"
};

jQuery(document).ready(function () {
	_viewModels.Elections = new ElectionDropDownViewModel(inputViewModelSettings.electionsUrl, "earlyVoting");

	_viewModels.earlyVoting = new ElectionCollectionViewModel(inputViewModelSettings.electionUrl, inputViewModelSettings.baseUrl, "EarlyVotingLocations", { "electionCode": inputViewModelSettings.electionCode }, undefined, _viewModels.Elections.mapElectionCodeCallback);

	ko.applyBindings(_viewModels);
});
</script>

<!-- ko with: _viewModels.earlyVoting -->

<!-- ko if: loaded -->
<!-- ko with: EarlyVotingLocations -->
<h3 data-bind="css: { 'text-muted' : !loaded(), 'text-primary' : loaded }">
	<span class="h2">
		<strong>
			<font color="#000">
			<span style="display:block">Early Voting Locations</span>
			<span data-bind="text: $parent.item().ElectionDate"></span>
			<span data-bind="text: $parent.item().Description"></span> Election
			</font>
		</strong>
	</span>
	<!--<div style="height: 100%; vertical-align: bottom;" class="pull-right" data-bind="visible: loaded()">
		<span class="label label-default" data-bind="text: count"></span> <small>total</small>
	</div> -->
	<img src="/sites/all/modules/custom/candidate_filiing/images/spinner.gif" alt="Loading" data-bind="visible: !loaded()" />
</h3>
<!-- /ko -->

<div class="container app">
	<?php echo $text_dumcontent; ?>
</div>
<div class="candidate-bar earlyVoting">
	<div class="candidate-info container">
		<div class="form-item form-item-status-filter form-type-select form-group">
			<!-- ko with: _viewModels.Elections -->
			<label class="control-label" for="edit-status-filter">Election Date</label>
			<select class="form-control form-select" id="edit-status-filter" name="edit-status-filter" data-bind="options: item, optionsText: 'ElectionDate', optionsValue: 'ElectionCode', value: _viewModels.earlyVoting.EarlyVotingLocations.query().electionCode"></select>
			<!-- /ko -->
		</div>
			<!-- ko with: EarlyVotingLocations -->
	<button type="button" id="edit-status-submit" name="status_submit" value="Apply" class="btn btn-info form-submit" data-bind="click: fetch">Apply</button>
	<!-- /ko -->
	</div>
</div>

<!-- ko with: EarlyVotingLocations -->
	<!-- ko if: loaded -->

	<table class="table table-bordered table-striped early-voting" style="display: none;" data-bind="visible: item().length > 0">
		<thead>
			<tr>
				<th style="width:190px;">Location</th>
				<th>
					<div class="row">
						<div class="col-sm-4 text-center">Monday-Friday</div>
						<hr class="visible-xs" />
						<div class="col-sm-4 text-center">Saturday</div>
						<hr class="visible-xs" />
						<div class="col-sm-4 text-center">Sunday</div>
					</div>
				</th>
			</tr>
		</thead>
		<tbody data-bind="foreach: item">
			<tr>
				<td style="width:190px;">
					<div data-bind="text: Name"></div>
					<div>
						<a data-bind="attr: { href: 'https://maps.google.com?q=' + encodeURIComponent( (LocationAddress.Address1 && LocationAddress.Address1() ? (LocationAddress.Address1() + ', ') : '') + (LocationAddress.Zip && LocationAddress.Zip() ? LocationAddress.Zip() : 'IL') ) }" target="_blank">
							<div data-bind="text: LocationAddress.Address1"></div>
							<div data-bind="text: LocationAddress.Address2"></div>
							<div data-bind="visible: LocationAddress.State">
								<span data-bind="text: LocationAddress.City"></span><span data-bind="visible: LocationAddress.City">, </span>
								<span data-bind="text: LocationAddress.State"></span>
								<span data-bind="text: LocationAddress.Zip"></span>
							</div>
						</a>
					</div>
				</td>
				<td>
					<div class="row">
						<!-- ko foreach: LocationSchedule -->
						<div class="col-sm-4 text-center">
							<span class="sr-only" data-bind="text: Code"></span>

							<!-- ko foreach: Schedule -->
							<div class="row date" data-bind="visible: StartDate">
								<div class="col-sm-12">
									<span data-bind="text: StartDate"></span>
									<span data-bind="visible: EndDate"> - </span>
									<span data-bind="text: EndDate"></span>
								</div>
							</div>
							<div class="row" data-bind="visible: StartTime">
								<div class="col-sm-12">
									<span data-bind="text: StartTime"></span>
									<span data-bind="visible: EndTime"> - </span>
									<span data-bind="text: EndTime"></span>
								</div>
							</div>
							<!-- /ko -->
							<hr class="visible-xs" />
						</div>
						<!-- /ko -->
					</div>
				</td>
			</tr>
		</tbody>
	</table>

	<!-- No Results -->
	<p class="alert alert-info" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && !failed() && item().length <= 0">
		<!--<span class="glyphicon glyphicon-info-sign" aria-hidden="true"></span>-->
		<span class="sr-only">No Results:</span>
		No data is currently available
	</p>

	<!-- Error -->
	<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed()">
		<!--<span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>-->
		<span class="sr-only">Error:</span>
		An unexpected problem has occurred while retrieving data. <span data-bind="visible: failedMessage && failedMessage(), text: failedMessage"></span>
	</p>

	<!-- /ko -->
<!-- /ko -->

<!-- Outer Error -->
<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed() && failedMessage && failedMessage()">
	<span data-bind="text: failedMessage"></span>
</p>
<!-- /ko -->

<!-- /ko -->

<script type="text/javascript">
jQuery(document).ready(function() {
	_viewModels.Elections.fetch();
});
</script>
