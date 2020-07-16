<?php
$text_content = variable_get('text_content', '');
?>

<!-- TODO: please move me into outline CSS file -->
<style type="text/css">
	#candidates-candidate-statement-body-text {
		border: none !important;
		background-color: transparent !important;
		resize: none !important;
		overflow: auto !important;
		outline: none !important;

		-webkit-box-shadow: none;
		-moz-box-shadow: none;
		box-shadow: none;

		width: 100%;
		height: 250px;
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
		baseUrl: "/api/Candidate/GetAllCandidates",
		partyOptionsUrl: "/api/Candidate/GetPartyList",
		candidateStatementUrl: "/api/Candidate/GetCandidateStatementById/",
		electionCode: "0",
		partyCodeAll: "",
		dropDownOptions: [],
		codeToNameMapping: {},
		partyCodeToName: function (code) {
			if (!code) {
				return "";
			}

			if (this.codeToNameMapping.hasOwnProperty(code)) {
				return this.codeToNameMapping[code];
			}

			return code;
		}
	};

	jQuery(document).ready(function () {
		ko.options.deferUpdates = true;

		_viewModels.Elections = new ElectionDropDownViewModel(inputViewModelSettings.electionsUrl, "candidates");

		_viewModels.candidates = new ElectionCollectionViewModel(
			inputViewModelSettings.electionUrl,
			inputViewModelSettings.partyOptionsUrl,
			"Parties",
			{"electionCode": inputViewModelSettings.electionCode},
			function (result, inputQuery) {
				var candidateQuery = _viewModels.candidates.Candidates.query();
				candidateQuery.electionCode = result.ElectionCode;

				if (result && result.IsPrimary && !!result.IsPrimary()) {
					candidateQuery.partyCode = undefined;
					_viewModels.candidates.Candidates.query(candidateQuery);

					return true;
				}

				candidateQuery.partyCode = inputViewModelSettings.partyCodeAll;
				_viewModels.candidates.Candidates.query(candidateQuery);

				_viewModels.candidates.Candidates.fetch();

				return true;
			},
			function (result) {
				if (result.Parties) {
					var codeToNameMappingLocal = {};
					jQuery.each(result.Parties, function (i, party) {
						codeToNameMappingLocal[party.PartyCode] = party.Description;
					});

					inputViewModelSettings.codeToNameMapping = jQuery.extend({}, inputViewModelSettings.codeToNameMapping, codeToNameMappingLocal);
				}
			}
		);

		_viewModels.candidateStatement = new SingleViewModel(inputViewModelSettings.candidateStatementUrl, "data");

		_viewModels.candidates.Candidates = new CollectionViewModel(inputViewModelSettings.baseUrl, "Candidates", {
				"electionCode": inputViewModelSettings.electionCode,
				"partyCode": inputViewModelSettings.partyCodeAll
			}
			/*function(newValue) {
				_viewModels.Elections.mapElectionCodeCallback(undefined, this.query().electionCode());

				return true;
			}*/
		);

		ko.computed(function() {
			return ko.toJSON(_viewModels.candidates.Candidates.query);
		}).extend({ deferred: true }).subscribe(function() {
			// called whenever any of the properties of complexObject changes
			if (this && this.query && this.query() && this.query().electionCode) {
				_viewModels.Elections.mapElectionCodeCallback(undefined, this.query().electionCode());

				//debugger;
			}


		}, _viewModels.candidates.Candidates);

		_viewModels.candidates.item.extend({ deferred: true }).subscribe(function(result) {
			if (_viewModels.candidates.Parties.query().electionCode === result.ElectionCode())
				return;

			var partyQuery = _viewModels.candidates.Parties.query();
			var candidateQuery = _viewModels.candidates.Candidates.query();

			if (ko.isObservable(partyQuery.electionCode))
				partyQuery.electionCode(result.ElectionCode());
			else
				partyQuery.electionCode = result.ElectionCode();

			_viewModels.candidates.Parties.query(partyQuery);

			if (result && result.IsPrimary && !!result.IsPrimary()) {
				if (ko.isObservable(candidateQuery.partyCode))
					candidateQuery.partyCode(undefined);
				else
					candidateQuery.partyCode = undefined;
				/**/

				_viewModels.candidates.Candidates.query(candidateQuery);

				_viewModels.candidates.Parties.fetch();

				return;
			}

			if (ko.isObservable(candidateQuery.partyCode))
				candidateQuery.partyCode(inputViewModelSettings.partyCodeAll);
			else
				candidateQuery.partyCode = inputViewModelSettings.partyCodeAll;
			/**/

			_viewModels.candidates.Candidates.query(candidateQuery);

			/*if (ko.isObservable(candidateQuery.partyCode))
				candidateQuery.partyCode(inputViewModelSettings.partyCodeAll);
			else
				candidateQuery.partyCode = inputViewModelSettings.partyCodeAll;*/

			//_viewModels.candidates.Candidates.query(candidateQuery);

			//debugger;

			return;
		});

		ko.applyBindings(_viewModels);
	});
</script>

<!-- ko with: _viewModels.candidates -->

<!-- ko if: loaded -->
<!-- ko with: Candidates -->
<h3 data-bind="css: { 'text-muted' : !$parent.loaded() || refreshing() }">
		<span class="h2">
			<strong>
			<span style="display:block">Candidates</span>
			<span data-bind="text: $parent.item().ElectionDate"></span>
			<span data-bind="text: $parent.item().Description"></span> Election
			</strong>
		</span>
	<img src="/sites/all/modules/custom/candidate_filiing/images/spinner.gif" alt="Loading"
	     data-bind="visible: !$parent.loaded() || refreshing()"/>
</h3>
<!-- /ko -->

<div class="container app">
	<?php echo $text_content; ?>
</div>
<div class="candidate-bar">
	<div class="candidate-info container view-all">
		<div class="form-item form-item-status-filter candidates form-type-select form-group">
			<!-- ko with: _viewModels.Elections -->
			<label class="control-label" for="edit-status-filter">Election Date</label>
			<select class="form-control form-select" id="edit-status-filter" name="edit-status-filter" data-bind="options: item, optionsText: 'ElectionDate', optionsValue: 'ElectionCode', value: _viewModels.candidates.Candidates.query().electionCode"></select>
			<!-- /ko -->

			<!-- ko if: item && item() && item().IsPrimary -->
			<!-- ko with: Parties -->
			<label class="control-label" for="edit-status-filter">Political Party</label>
			<select class="form-control form-select" id="edit-status-filter" name="edit-status-filter" data-bind="options: item(), optionsCaption: 'Choose a Political Party', optionsText: 'Description', optionsValue: 'PartyCode', value: _viewModels.candidates.Candidates.query().partyCode, valueAllowUnset: true"></select>
			<!-- /ko -->
			<!-- /ko -->
		</div>
		<!-- ko with: Candidates -->
		<button type="button" id="edit-status-submit" name="status_submit" value="Apply" class="btn btn-info form-submit" data-bind="click: fetch">Apply
		</button>
		<!-- /ko -->
	</div>
</div>

<!-- ko with: Candidates -->
<!-- ko if: loaded -->

<!-- ko foreach: item -->
<div class="candidates-container">
	<div class="candidates-header">
		<h4>
			<span data-bind="text: Office"></span>, <span data-bind="text: Name"></span>
			<span data-bind="visible: Vacancy"> <span data-bind="text: Vacancy"></span></span>
		</h4>
		<div class="text-muted">
			<span data-bind="visible: Unexpired"><span data-bind="text: Unexpired"></span> </span><span data-bind="visible: TermDisplay && TermDisplay()"><span data-bind="text: Term"></span> Year Term, </span>
      <span data-bind="visible: !Retention()">Vote For <span data-bind="text: Vote"></span></span><span data-bind="visible: Retention">Vote Yes or No</span>
		</div>
	</div>

	<table class="table table-bordered table-striped" style="display: none;" data-bind="visible: item().length > 0">
		<thead>
		<tr>
			<th>Candidate Name</th>
			<th>Party</th>
            <th style="text-align:center">
                <span data-bind="visible: Retention">Yes</span>
                <span data-bind="visible: !Retention()">Ballot #</span>
            </th>
			<th style="text-align:center" data-bind="visible: Retention">No</th>
		</tr>
		</thead>
		<tbody data-bind="foreach: item">
		<tr>
			<td data-bind="css: { 'candidates-has-statement': StmntId }" style="word-break:break-word;">
				<!-- ko if: StmntId -->
				<a href="#" data-bind="click: function() { jQuery('#candidates-candidate-statement-modal-lg').modal(); _viewModels.candidateStatement.fetch(StmntId()); }"><span data-bind="text: Name"></span></a>
				<!-- /ko -->
				<!-- ko ifnot: StmntId -->
				<span data-bind="text: Name"></span>
				<!-- /ko -->
			</td>
			<td data-bind="text: inputViewModelSettings.partyCodeToName(Pty())"></td>
			<td data-bind="text: Num" style="text-align:center;"></td>
			<td data-bind="visible: $parent.Retention, text: NoNum" style="text-align:center;"></td>
		</tr>
		</tbody>
	</table>
</div>
<!-- /ko -->

<!-- Error -->
<!--<p class="alert alert-info" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && !failed() && item().length <= 0">-->
	<!--<span class="glyphicon glyphicon-info-sign" aria-hidden="true"></span>-->
<!--<span class="sr-only">No Results:</span>
No results. Please choose a political party option from the dropdown.
</p>-->

<!-- Error -->
<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed()">
	<!--<span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>-->
	<span class="sr-only">Error:</span>
	Information could not be provided. <span data-bind="visible: failedMessage && failedMessage(), text: failedMessage"></span>
</p>

<!-- /ko -->
<!-- /ko -->

<!-- Outer Error -->
<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed() && failedMessage && failedMessage()">
	<span data-bind="text: failedMessage"></span>
</p>
<!-- /ko -->

<!-- /ko -->

<!-- Candidate Statement Modal -->
<div id="candidates-candidate-statement-modal-lg" class="modal fade" tabindex="-1" role="dialog" aria-labelledby="candidateStatementModalLabel">
	<div class="modal-dialog" role="document">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span>
				</button>
				<h4 class="modal-title text-uppercase text-muted" id="candidateStatementModalLabel">Candidate Statement</h4>
			</div>
			<div class="modal-body">
				<div class="row">
					<div class="col-md-12">
						<!-- ko with: _viewModels.candidateStatement -->

						<div data-bind="visible: refreshing">
							<div class="progress">
								<div class="progress-bar progress-bar-striped active" role="progressbar" aria-valuenow="100" aria-valuemin="0" aria-valuemax="100" style="width: 100%">
									<span class="sr-only">Loading...</span>
								</div>
							</div>
						</div>

						<!-- ko if: loaded -->

						<!-- ko with: item -->
						<div>
							<h2 style="margin-top:0px;">
								<span data-bind="text: candidateName"></span><br/>
								<span class="small" data-bind="text: office"></span><span class="small" data-bind="visible: jurisdiction() && office()">, </span><span class="small" data-bind="text: jurisdiction"></span>
							</h2>

							<br/>

							<!--<div data-bind="text: statementBody"></div>-->
							<textarea id="candidates-candidate-statement-body-text" data-bind="value: statementBody" readonly="readonly"></textarea>

							<br/>

							<div data-bind="foreach: urls">
								<span data-bind="visible: linkLabel">
									<span data-bind="text: linkLabel"></span>:
								</span>
								<a target="_blank" data-bind="attr: { 'href': linkUrl }, text: linkText"></a>
								<br/>
							</div>
						</div>
						<!-- /ko -->

						<p class="alert alert-danger" style="display: none; margin-bottom: 40px;" data-bind="visible: loaded() && failed()">
							<!--<span class="glyphicon glyphicon-exclamation-sign" aria-hidden="true"></span>-->
							<span class="sr-only">Error:</span>
							There was a problem displaying the requested information. <span data-bind="visible: failedMessage && failedMessage(), text: failedMessage"></span>
						</p>

						<!-- /ko -->

						<!-- /ko -->
					</div>
				</div>
			</div>
			<div class="modal-footer">
				<button type="button" class="btn btn-default" data-dismiss="modal">Close</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->

<script type="text/javascript">
	jQuery(document).ready(function () {
		_viewModels.Elections.fetch();
	});
</script>
