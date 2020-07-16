<?php
/**
 * @file
 * basic_page_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function basic_page_content_type_taxonomy_default_vocabularies() {
  return array(
    'agency_hierarchy' => array(
      'name' => 'Agency Hierarchy',
      'machine_name' => 'agency_hierarchy',
      'description' => 'This taxonomy controls the cascading permissions and the agency placement in the org structure.',
      'hierarchy' => 1,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
