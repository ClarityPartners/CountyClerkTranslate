<?php

/**
 * @param $data
 *
 * @return array
 */
function voter_tool_theme_voter_info ($data) {
  $voter_form = array();
  foreach ($data['voter_info'] as $voter_id => $voter) {
    $voter_form[$voter_id] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => $voter['name'] . ' ' . $voter['township'] . ' Precinct ' . substr($voter['precinct_number'], -3) . ' ' . $voter['status'],
    );
    $voter = '';
    $voter .= '<div class="' . $voter_id . '">';
    $voter .= 'Voter Name : ' . $voter['name'] . '<br>';
    $voter .= 'Voter Address : <div class="voterAddress">' . $voter['address']['street'] . ', ' . $voter['address']['city'] . ' ' . $voter['address']['zipcode'] . '</div><br>';
    $voter .= 'Precinct Number : ' . $voter['precinct_number'] . '<br>';
    $voter .= '</div>';
    $voter_form[$voter_id]['markup'] = array(
      '#markup' => $voter,
    );
  }

  return $voter_form;
}

function voter_tool_theme_ballot ($data) {
  $primary = $data['ballot']['primary'];
  $precinct = $data['ballot']['precinctId'];
  $split = $data['ballot']['groupId'];
  $parties = $data['ballot']['parties'];
  $html = '';

  if ($primary) {
    foreach ($parties as $party) {
      $html .= '<div class="ballot-link"><a href="/service/sample-ballot/' . $precinct . '/' . $split . '/' . $party['PartyCode'] . '" target="blank">View the ' . $party['Description'] . ' ballot.</a></div>';
    }
  } else {
    $html .= '<div class="ballot-link"><a href="/service/sample-ballot/' . $precinct . '/' . $split . '" target="blank">View the ballot.</a></div>';
  }

  return $html;
}

/**
 * @param $data
 *
 * @return string
 */
function voter_tool_theme_print_ballot ($data) {
  $races = $data['ballot']['races'];
  $referendums = $data['ballot']['referendums'];
  $html = '<div class="ballot-intro">Close this window to return to Your Voter Information page.</div>';
  if (count($races) > 0 || !empty($referendums[0]['ReferendumText'])) {
    $html .= '<div id="printable-ballot">';
    if (count($races) > 0) {
      $election_date = date('F j, Y', strtotime($races[0]['ElectionDate']));
      $election_type = $races[0]['ElectionType'];
      $html .= "<h3 class='election-name'>Races for $election_date - $election_type Election</h3>";

      // Add print buttons
    $html .= '<div class="print-buttons top">';
    // Not doing email right now.
    //  $html .= '<span class="email email-ballot"><a id="email-my-ballot" href="mailto:?subject=hello&body=this is the body">Email My Selected Candidates</a></span>';
    //$html .= '<span class="print print-ballot"><a id="print-my-ballot">Print My Selected Candidates</a></span>';
    $html .= '<span class="print print-ballot"><a id="print-whole-ballot">Print Sample Ballot</a></span>';
    $html .= '</div>';

      $candidate_header = <<<HTML
    <div class="candidate-header no-print">
      <div class="name no-print">Candidate Name</div>
      <div class="party no-print">Party</div>
      <div class="ballot-number no-print">Ballot #</div>
      <div class="ballot-save no-print">Save To Sample Ballot</div>
    </div>
HTML;
    $candidate_header_yes = <<<HTML
    <div class="candidate-header no-print">
      <div class="name no-print">Candidate Name</div>
      <div class="party no-print">Party</div>
      <div class="ballot-number no-print">Yes</div>
      <div class="ballot-save no no-print">No</div>
    </div>
HTML;
      $referendum_header = <<<HTML
    <div class="referendum-header">
      <div class="name">Question</div>
      <div class="ballot-save">Save To Sample Ballot</div>
    </div>
HTML;
      foreach ($races as $election) {
        if(($election['OfficeName'] == 'Judge') || ($election['OfficeId'] == 'DLGTE') || ($election['OfficeId'] == 'ALTDG')) {
          $election['TermYears'] = '';
        } else {
          $election['TermYears'] = $election['TermYears'] . ' Year Term,';
        }
        if($election['Vacancy']){
          $election['Vacancy'] = $election['Vacancy'].',';
        }
        $html .= '<div class="race no-print"><div class="race-title">' . $election['OfficeName'] . ', ' . $election['JurisdictionName'] . '</div>';
      if($election['Retention'] == 'true'){
        $html .= '<div class="term-data">' . $election['TermYears'] . $election['Vacancy'] .' Vote Yes or No</div>';
      } else{
        $html .= '<div class="term-data">' . $election['TermYears'] . $election['Vacancy'] .' Vote For ' . $election['VoteFor'] . '</div>';
      }

        $html .= '<div class="candidates">';

      if($election['Retention'] == 'true'){
        $html .= $candidate_header_yes;
        foreach ($election['CandidateBallotDetails'] as $candidate) {
          if(isset($candidate['statement']) != NULL){
            $link = '';
            foreach($candidate['urls'] as $links){
              $link .= '<span>'.$links['linkLabel'].': '.'<a href="'.$links['linkUrl'].'">'.$links['linkText'].'</a></span>';
            }
            $html .= '<div class="candidate-row no-print">';
            $html .= '  <div class="name"><a id="canstate">' . $candidate['FullName'] . '</a></div>';
            $html .= '  <div class="party">' . $candidate['Party'] . '</div>';
            $html .= '  <div class="ballot-number">' . $candidate['BallotNumber'] . '</div>';
            $html .= '  <span class="ballot-save no">' . $candidate['NoBallotNumber'] . '</span>';
            $html .= ' <div id="statementDiv" class="modal fade"><div class="modal-dialog"><div class="modal-content"><div class="modal-header"><button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">×</span></button><h4 class="modal-title">Candidate Statement</h4></div><div class="modal-body"><div class="row"><div class="col-md-12"><div class="candNameTitle"><h2>'.$candidate['FullName'].'</h2><span>'.$election['OfficeName'] . ', ' . $election['JurisdictionName'].'</span></div><textarea id="candidates-candidate-statement-body-text">'.$candidate['statement'].'</textarea><div class="modalLinks">'. $link .'</div></div></div></div><div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div></div></div></div>';
            $html .= '</div>';
          } else{
            $html .= '<div class="candidate-row no-print">';
            $html .= '  <div class="name">' . $candidate['FullName'] . '</div>';
            $html .= '  <div class="party">' . $candidate['Party'] . '</div>';
            $html .= '  <div class="ballot-number">' . $candidate['BallotNumber'] . '</div>';
            $html .= '  <span class="ballot-save no">' . $candidate['NoBallotNumber'] . '</span>';
            $html .= '</div>';
          }
        }
      } else {
        $html .= $candidate_header;
        foreach ($election['CandidateBallotDetails'] as $candidate) {
          if(isset($candidate['statement']) != NULL){
            $link = '';
            foreach($candidate['urls'] as $links){
              $link .= '<span>'.$links['linkLabel'].': '.'<a href="'.$links['linkUrl'].'">'.$links['linkText'].'</a></span>';
            }
            $html .= '<div class="candidate-row no-print">';
            $html .= '  <div class="name"><a id="canstate">' . $candidate['FullName'] . '</a></div>';
            $html .= '  <div class="party">' . $candidate['Party'] . '</div>';
            $html .= '  <div class="ballot-number">' . $candidate['BallotNumber'] . '</div>';
            $html .= '  <span class="ballot-save"><input type="checkbox" value="' . $candidate['BallotNumber'] . '" id="ballot-' . $candidate['BallotNumber'] . '-save" name="check" /><label for="ballot-' . $candidate['BallotNumber'] . '-save" class="switch"></label><span class="slider"></span></span>';
            $html .= ' <div id="statementDiv" class="modal fade"><div class="modal-dialog"><div class="modal-content"><div class="modal-header"><button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">×</span></button><h4 class="modal-title">Candidate Statement</h4></div><div class="modal-body"><div class="row"><div class="col-md-12"><div class="candNameTitle"><h2>'.$candidate['FullName'].'</h2><span>'.$election['OfficeName'] . ', ' . $election['JurisdictionName'].'</span></div><textarea id="candidates-candidate-statement-body-text">'.$candidate['statement'].'</textarea><div class="modalLinks">'. $link .'</div></div></div></div><div class="modal-footer"><button type="button" class="btn btn-default" data-dismiss="modal">Close</button></div></div></div></div>';
            $html .= '</div>';
          } else{
            $html .= '<div class="candidate-row no-print">';
            $html .= '  <div class="name">' . $candidate['FullName'] . '</div>';
            $html .= '  <div class="party">' . $candidate['Party'] . '</div>';
            $html .= '  <div class="ballot-number">' . $candidate['BallotNumber'] . '</div>';
            $html .= '  <span class="ballot-save"><input type="checkbox" value="' . $candidate['BallotNumber'] . '" id="ballot-' . $candidate['BallotNumber'] . '-save" name="check" /><label for="ballot-' . $candidate['BallotNumber'] . '-save" class="switch"></label><span class="slider"></span></span>';
            $html .= '</div>';
          }
        }


      }

        // close div candidates.
        $html .= '</div></div>';
      }
    }
    if (!empty($referendums[0]['ReferendumText'])) {
      $referendum_type = $referendums[0]['ElectionTypeDescription'];
      $referendum_date = date('F j, Y', strtotime($referendums[0]['ElectionDate']));
      $html .= "<h3 class='election-name referendum'>Referenda for $referendum_date - $referendum_type Election</h3>";

      foreach ($referendums as $referendum) {
        $html .= '<div class="referendum race no-print"><div class="referendum-title">' . $referendum['LongTitle'] . '</div>';
        $html .= $referendum_header;
        $html .= '<div class="referendum-row">';
        $html .= '<div class="question">' . $referendum['ReferendumText'] . '</div>';
        $html .= '<span class="ballot-save"><input type="checkbox" value="' . $referendum['YesPunchNumber'] . '" id="ballot-' . $referendum['YesPunchNumber'] . '-save" name="check" /><label for="ballot-' . $referendum['YesPunchNumber'] . '-save" class="switch"></label><span class="slider"></span></span>';
        $html .= '</div>';
        $html .= '</div>';
      }
    }
    // End of printable-ballot div.
    $html .= '</div>';
    // Add print buttons
    $html .= '<div class="print-buttons">';
    // Not doing email right now.
    //  $html .= '<span class="email email-ballot"><a id="email-my-ballot" href="mailto:?subject=hello&body=this is the body">Email My Selected Candidates</a></span>';
    //$html .= '<span class="print print-ballot"><a id="print-my-ballot">Print My Selected Candidates</a></span>';
    $html .= '<span class="print print-ballot"><a id="print-whole-ballot-2">Print Sample Ballot</a></span>';
    $html .= '</div>';
  } else {
    $html .= '<div class="no-results">There does not appear to be a ballot for the selection you made. Please double check the information you entered and try again.</div>';
  }

  return $html;
}

/**
 * @param $data
 *
 * @return string
 */
function voter_tool_theme_polling ($data) {
  $polling = $data['polling'];
  $html = '';

  $html .= '<div class="pollingBox" style="height:800px;">';
  $html .= '<div class="mapLocation">';
  $html .= '<h4>'.$polling['address']['name'].'</h4><br/>';
  $html .= '<div id="pollingAddress">' . $polling['address']['street'] . '<br/> ' . $polling['address']['city'] . ' ' . $polling['address']['zipcode'] . '</div><br>';
  //$html .= 'Precinct Number : ' . $polling['precinct_number'] . '<br>';
  if ($polling['handicapped_accessible']) {
    $html .= '<div class="pollingDisabled">This location is accessible to the disabled.</div><br>';
  }
  $html .= '<span class="print-polling"><a id="print-polling-button">Print Directions</a></span>';
  $html .= '</div>';

  // Do the map stuff.
  $html .= '<div class="mapContainer"><div class="mapBounds" style="height:400px; width:100%;"><div id="pollingMap" style="height:100%;"></div></div>';
  $html .= '<div id="pollingDirectionsPanel"></div>';
  $html .= '</div></div>';

  return $html;
}

/**
 * @param $data
 *
 * @return string
 */
function voter_tool_theme_mail_ballot ($data) {
  //need to add the url in here, just need to know how it should look
  $ballots = $data['mail_ballot'];
  if($ballots['ElectionDate'] == NULL){
    $ballots['ElectionDate'] = '2020-11-03T00:00:00'; //November 3rd 2020
  }

  $html = '<p>The following mail ballot status is for: ' . $ballots['voter_name'] . ' for the ' .  date('F j, Y', strtotime($ballots['ElectionDate'])) . ' election.</p>';

  $html .= <<<HTML
<div class="mail-ballot-header">
  <!--<span class="application-mailed">Application Mailed To You</span>-->
  <span class="application-received">Application Received By Clerk</span>
  <span class="ballot-mailed">Ballot Mailed To You</span>
  <span class="ballot-received">Ballot Received By Clerk</span>
  <span class="ballot-track">Track My Ballot</span>
</div>
HTML;
$application_mailed = !empty($ballots['ApplicationMailDate']) ? date('F j, Y', strtotime($ballots['ApplicationMailDate'])) : 'NA';
$application_return = !empty($ballots['ApplicationReturnDate']) ? date('F j, Y', strtotime($ballots['ApplicationReturnDate'])) : 'Not returned';
$ballet_mailed = !empty($ballots['BallotMailDate']) ? date('F j, Y', strtotime($ballots['BallotMailDate'])) : 'NA';
$ballet_return = !empty($ballots['BallotReturnDate']) ? date('F j, Y', strtotime($ballots['BallotReturnDate'])) : 'Not returned';

if($ballots[ImbPUrl]){
  $ballet_updates = '<span class="ballot-track"><a target="_blank" href="'.$ballots[ImbPUrl].'">Track Online</a></span>';
} else{
  $ballet_updates = 'Not Available';
}

    $html .= '<div class="mail-ballot-row">';
    //$html .= '<span class="application-mailed">'. $application_mailed . '</span>';
    $html .= '<span class="application-received">' . $application_return . '</span>';
    $html .= '<span class="ballot-mailed">' . $ballet_mailed . '</span>';
    $html .= '<span class="ballot-received">' . $ballet_return . '</span>';
    $html .= $ballet_updates;
    $html .= '</div>';


  return $html;
}

/**
 * @param $data
 *
 * @return string
 */
function voter_tool_theme_provisional ($data) {
  if(!empty($data['provisional'])){
    $provisionals = $data['provisional'];

  if(isset($provisionals[0]['ElectionDate']) == NULL){
    $provisionals[0]['ElectionDate'] = '2020-11-03T00:00:00'; //November 3rd 2020
  }

  $html = '<p>The following provisional ballot status is for: ' . $provisionals['voter_name'] . ' for the ' .  date('F j, Y', strtotime($provisionals[0]['ElectionDate'])) . ' election.</p>';
unset($provisionals['voter_name']);
  $html .= <<<HTML
<div class="provisional-header">
  <span class="accepted">Provisional Ballot Accepted</span>
  <span class="reason">Reason</span>
</div>
HTML;
  foreach ($provisionals as $provisional) {
    $html .= '<div class="provisional-row">';
    $html .= '<span class="accepted">' . $provisional['IsCounted'] . '</span>';
    $html .= '<span class="reason">' . $provisional['Reason'] . '</span>';
    $html .= '</div>';
  }

  return $html;
  }
}

/**
 * @param $data
 *
 * @return string
 */
function voter_tool_theme_early_voting ($data) {
  $early_voting = $data['early_voting'];
  $html = '';

  $html .= '<div class="earlyVotingBox" style="height:800px;">';
  $html .= '<div class="mapLocation">';
  $html .= '<h4>'.$early_voting['address']['name'] . '</h4><br/>';
  $html .= '<div id="earlyvotingAddress">' . $early_voting['address']['street'] . ' <br/>' . $early_voting['address']['city'] . ' ' . $early_voting['address']['zipcode'] . '</div><br>';
  //$html .= 'Early Voting Id : ' . $early_voting['early_voting_id'] . '<br>';
  $html .= '<span class="print-early-voting"><a id="print-early-voting-button">Print Directions</a></span>';
  $html .= '</div>';

  // Do the map stuff.
  $html .= '<div class="mapContainer"><div class="mapBounds" style="height:400px; width:100%;"><div id="earlyvotingMap" style="height:100%;"></div></div>';
  $html .= '<div id="earlyvotingDirectionsPanel"></div>';
  $html .= '</div></div>';

  return $html;
}
