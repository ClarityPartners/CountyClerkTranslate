<?php
/**
 * @file
 * search_api_solr_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function search_api_solr_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function search_api_solr_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function search_api_solr_search_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_page_primary_search'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_page_primary_search",
    "name" : "Primary Search",
    "index_id" : "primary_search",
    "suggester_id" : "server",
    "type" : "search_api_page",
    "enabled" : "1",
    "options" : {
      "custom" : { "page_id" : "primary_search" },
      "results" : true,
      "fields" : []
    }
  }');
  $items['search_api_views_primary_search_view'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_primary_search_view",
    "name" : "Primary Search View",
    "index_id" : "primary_search",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : { "results" : true, "fields" : [] }
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function search_api_solr_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "local",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "publication" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-50",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-49", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 1, "weight" : "-48", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 1, "weight" : "-47", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "-46", "settings" : { "mode" : "full" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-45", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-44", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "-43",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "title" : true,
              "body:value" : true,
              "field_publication_image:file:name" : true
            }
          }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "field_publication_image:file:name" : true
            },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "field_publication_image:file:name" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "field_publication_image:file:name" : true
            },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : {
              "title" : true,
              "body:value" : true,
              "field_publication_image:file:name" : true
            },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      },
      "fields" : {
        "attachments_field_event_documents" : { "type" : "text" },
        "attachments_field_publication_file" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_publication_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_publication_description:value" : { "type" : "text" },
        "field_publication_image:file" : { "type" : "integer", "entity_type" : "file" },
        "field_publication_image:file:name" : { "type" : "text" },
        "field_publication_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "search_api_url" : { "type" : "uri" },
        "search_api_viewed" : { "type" : "text" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  $items['primary_search'] = entity_import('search_api_index', '{
    "name" : "Primary search",
    "machine_name" : "primary_search",
    "description" : null,
    "server" : "local",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [
          "agency",
          "event",
          "location",
          "news",
          "publication",
          "service",
          "video"
        ]
      },
      "index_directly" : 0,
      "cron_limit" : "50",
      "fields" : {
        "attachments_field_documents" : { "type" : "text" },
        "attachments_field_event_documents" : { "type" : "text" },
        "attachments_field_publication_file" : { "type" : "text" },
        "attachments_field_video" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "created" : { "type" : "date" },
        "field_agency_description:value" : { "type" : "text" },
        "field_agency_display" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_agency_document" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_agency_main_location" : { "type" : "integer", "entity_type" : "node" },
        "field_agency_other_locations" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_agency_parent" : { "type" : "integer", "entity_type" : "node" },
        "field_agency_related" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_agency_services" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_agency_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_at_this_location" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_banner_related_pages" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_banner_track_clicks" : { "type" : "boolean" },
        "field_basic_body:value" : { "type" : "text" },
        "field_body:value" : { "type" : "text" },
        "field_broadcast_message" : { "type" : "text" },
        "field_broadcast_related_pages" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_broadcast_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_cards" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "paragraphs_item" },
        "field_date_and_time:duration" : { "type" : "list\\u003Cduration\\u003E" },
        "field_date_and_time:value" : { "type" : "list\\u003Cdate\\u003E" },
        "field_date_and_time:value2" : { "type" : "list\\u003Cdate\\u003E" },
        "field_description:summary" : { "type" : "text" },
        "field_description:value" : { "type" : "text", "boost" : "13.0" },
        "field_event_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_event_host" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_event_location" : { "type" : "integer", "entity_type" : "node" },
        "field_event_location:field_agency_display" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_location:field_location_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_event_location:title" : { "type" : "text" },
        "field_event_location:type" : { "type" : "string" },
        "field_event_location_detail" : { "type" : "text" },
        "field_event_related_pages" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_faq" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_faq:field_faq_question" : { "type" : "list\\u003Ctext\\u003E" },
        "field_faq_placement" : { "type" : "integer", "entity_type" : "node" },
        "field_icon_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_image_orientation" : { "type" : "decimal" },
        "field_landing_page" : { "type" : "boolean" },
        "field_link_type" : { "type" : "string" },
        "field_location:additional" : { "type" : "text" },
        "field_location:city" : { "type" : "text" },
        "field_location:country" : { "type" : "text" },
        "field_location:country_name" : { "type" : "text" },
        "field_location:name" : { "type" : "text" },
        "field_location:postal_code" : { "type" : "text" },
        "field_location:street" : { "type" : "text" },
        "field_location_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_location_email" : { "type" : "text" },
        "field_location_phone" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "field_collection_item"
        },
        "field_location_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_main_service_provider" : { "type" : "integer", "entity_type" : "node" },
        "field_media_contact" : { "type" : "integer", "entity_type" : "node" },
        "field_media_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_news_author" : { "type" : "text" },
        "field_news_category" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_news_gov_references" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_person_email" : { "type" : "text" },
        "field_publication_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_publication_description:value" : { "type" : "text" },
        "field_publication_file:file:field_file_image_title_text" : { "type" : "text" },
        "field_publication_file:file:name" : { "type" : "text" },
        "field_publication_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_related_publications" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_service_description:value" : { "type" : "text" },
        "field_service_document" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_service_main_location" : { "type" : "integer", "entity_type" : "node" },
        "field_service_other_location" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_service_related_serv_prog" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_service_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "search_api_language" : { "type" : "string" },
        "search_api_viewed" : { "type" : "text" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "agency" : "agency",
              "event" : "event",
              "faq" : "faq",
              "location" : "location",
              "news" : "news",
              "publication" : "publication",
              "service" : "service",
              "video" : "video"
            }
          }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "search_index" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_attachments_entityreference_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : { "fields" : [], "exceptions" : "texan=texa" }
        },
        "search_api_highlighting" : {
          "status" : 1,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 1
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function search_api_solr_search_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "10.252.29.200",
      "port" : "8983",
      "path" : "\\/solr\\/cclerk",
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 1,
      "highlight_data" : 1,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 0,
      "log_response" : 0,
      "commits_disabled" : 0,
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "0"
  }');
  return $items;
}
