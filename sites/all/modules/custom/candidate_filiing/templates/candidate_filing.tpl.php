<?php
	$text_body = variable_get('text_variable', '');
?>

<script type="text/javascript">
	jQuery('h1.page-header').hide();

	if (typeof _viewModels === "undefined" || !_viewModels) {
		var _viewModels = { isRoot: ko.observable(true) };
	}

	var inputViewModelSettings = {
		electionUrl: "/api/Election/GetCurrentElectionForAPI",
		electionsUrl: "/api/Election/GetAll",
		baseUrl: "/api/Candidate/GetFilingInfo",
		electionCode: "0",
		statusAll: "A",
		dropDownOptions: [
			{
				"Status": "A",
				"StatusDescription": "All"
			},
			{
				"Status": "C",
				"StatusDescription": "Challenged"
			},
			{
				"Status": "R",
				"StatusDescription": "Removed"
			},
			{
				"Status": "W",
				"StatusDescription": "Withdrawn"
			}
		]
	};

	jQuery(document).ready(function () {
		_viewModels.Elections = new ElectionDropDownViewModel(inputViewModelSettings.electionsUrl, "candidateFiling");

		_viewModels.candidateFiling = new ElectionCollectionViewModel(inputViewModelSettings.electionUrl, inputViewModelSettings.baseUrl, "CandidateFilings", { "electionCode": inputViewModelSettings.electionCode, "status": inputViewModelSettings.statusAll }, undefined, _viewModels.Elections.mapElectionCodeCallback);

		_viewModels.candidateFilingOption = new DropDownViewModel(inputViewModelSettings.dropDownOptions, "Status", "StatusDescription");

		ko.applyBindings(_viewModels);
	});
</script>

<!-- ko with: _viewModels.candidateFiling -->

<!-- ko if: loaded -->
	<!-- ko with: CandidateFilings -->
	<h3 data-bind="css: { 'text-muted' : !loaded(), 'text-primary' : loaded }">
		<span class="h2">
			<strong>
				<font color="#000">
					Candidate Filing - <span data-bind="text: $parent.item().ElectionDate"></span> <span data-bind="text: $parent.item().Description"></span> Election
				</font>
			</strong>
		</span>
		<div style="height: 100%; vertical-align: bottom;" class="pull-right" data-bind="visible: loaded()">
			<span class="label label-default" data-bind="text: count"></span> <small>total</small>
		</div>
		<img src="/sites/all/modules/custom/candidate_filiing/images/spinner.gif" alt="Loading" data-bind="visible: !loaded()" />
	</h3>
	<!-- /ko -->

	<div class="container">
		<?php echo $text_body; ?>
		<a href="/agency/elections" class="elections-btn" style="display:block; float:right; padding: 0 0 20px 0;text-decoration: underline;font-weight: 700;">Back to Elections</a>
	</div>
	<div class="candidate-bar">
		<div class="candidate-info container">
			<div class="form-item form-item-status-filter form-type-select form-group">
				<!-- ko with: _viewModels.Elections -->
				<label class="control-label" for="edit-status-election-filter">Election Date</label>
				<select class="form-control form-select" id="edit-status-election-filter" name="edit-status-election-filter" data-bind="options: item, optionsText: 'ElectionDate', optionsValue: 'ElectionCode', value: _viewModels.candidateFiling.CandidateFilings.query().electionCode"></select>
				<!-- /ko -->
			</div>
		</div>
		<div class="candidate-info container">
			<div class="form-item form-item-status-filter form-type-select form-group">
				<!-- ko with: _viewModels.candidateFilingOption -->
				<label class="control-label" for="edit-status-filter">Filter by Status</label>
				<select class="form-control form-select" id="edit-status-filter" name="edit-status-filter" data-bind="options: options, optionsText: text, optionsValue: value, value: _viewModels.candidateFiling.CandidateFilings.query().status"></select>
				<!-- /ko -->
			</div>
			<!-- ko with: CandidateFilings -->
			<button type="button" id="edit-status-submit" name="status_submit" value="Apply" class="btn btn-info form-submit" data-bind="click: fetch">Apply</button>
			<!-- /ko -->
		</div>
	</div>

	<!-- ko with: CandidateFilings -->
		<!-- ko if: loaded -->
		<table class="table table-bordered table-striped cFiling" style="display: none;" data-bind="visible: item().length > 0">
			<thead>
				<tr>
					<th data-bind="sort: { arr: item, prop: 'Jurisdiction()' }">Jurisdiction</th>
					<th data-bind="sort: { arr: item, prop: 'Office()' }">Office</th>
					<th data-bind="sort: { arr: item, prop: 'Term()' }">Term</th>
					<th data-bind="sort: { arr: item, prop: 'FullName()' }">Candidate</th>
					<th data-bind="sort: { arr: item, prop: 'Party()' }">Party</th>
					<th data-bind="sort: { arr: item, prop: 'Address()' }">Address</th>
					<th data-bind="sort: { arr: item, prop: 'FilingDate()' }">Filing Date</th>
					<th data-bind="sort: { arr: item, prop: 'Status()' }">Status</th>
				</tr>
			</thead>
			<tbody data-bind="foreach: item">
				<tr>
					<td data-bind="text: Jurisdiction"></td>
					<td data-bind="text: Office"></td>
					<td data-bind="text: Term"></td>
					<td data-bind="text: FullName"></td>
					<td data-bind="text: Party"></td>
					<td><span  data-bind="text: Address"></span><br/><span data-bind="text: City"></span> <span data-bind="text: Zipcode"></span></td>
					<td><span data-bind="text: DateTimeUtility(FilingDate()).asDate()"></span><br/><span data-bind="text: DateTimeUtility(FilingDate()).asHourMinuteTime()"></span></td>
					<td data-bind="text: Status"></td>
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
