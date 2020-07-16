<?php
	$text_refcontent = variable_get('text_referenda', '');
?>

<script type="text/javascript">
jQuery('h1.page-header').hide();
jQuery('article.node-service').hide();

if (typeof _viewModels === "undefined" || !_viewModels) {
	var _viewModels = { isRoot: ko.observable(true) };
}

var inputViewModelSettings = {
	electionUrl: "/api/Election/GetCurrentElectionForAPI",
	electionsUrl: "/api/Election/GetAll",
	baseUrl: "/api/Candidate/GetAllReferenda",
	electionCode: "0"
};

jQuery(document).ready(function () {
	_viewModels.Elections = new ElectionDropDownViewModel(inputViewModelSettings.electionsUrl, "referenda");

	_viewModels.referenda = new ElectionCollectionViewModel(inputViewModelSettings.electionUrl, inputViewModelSettings.baseUrl, "BallotReferendums", { "electionCode": inputViewModelSettings.electionCode }, undefined, _viewModels.Elections.mapElectionCodeCallback);

	ko.applyBindings(_viewModels);
});
</script>

<!-- ko with: _viewModels.referenda -->

<!-- ko if: loaded -->
<!-- ko with: BallotReferendums -->
<h3 data-bind="css: { 'text-muted' : !loaded(), 'text-primary' : loaded }">
	<span class="h2">
		<strong>
			<font color="#000">
			<span style="display:block">Referenda</span>
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
	<?php echo $text_refcontent; ?>
</div>
<div class="candidate-bar">
	<div class="candidate-info container">
		<div class="form-item form-item-status-filter form-type-select form-group">
			<!-- ko with: _viewModels.Elections -->
			<label class="control-label" for="edit-status-filter">Election Date</label>
			<select class="form-control form-select" id="edit-status-filter" name="edit-status-filter" data-bind="options: item, optionsText: 'ElectionDate', optionsValue: 'ElectionCode', value: _viewModels.referenda.BallotReferendums.query().electionCode"></select>
			<!-- /ko -->
		</div>
		<!-- ko with: BallotReferendums -->
		<button type="button" id="edit-status-submit" name="status_submit" value="Apply" class="btn btn-info form-submit" data-bind="click: fetch">Apply</button>
		<!-- /ko -->
	</div>
</div>

<!-- ko with: BallotReferendums -->
	<!-- ko if: loaded -->

	<table class="table table-bordered table-striped" style="display: none;" data-bind="visible: item().length > 0">
		<thead>
			<tr>
				<th>Title</th>
				<th>Question</th>
			</tr>
		</thead>
		<tbody data-bind="foreach: item">
			<tr>
				<td data-bind="text: LongTitle"></td>
				<td data-bind="text: ReferendumText"></td>
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
