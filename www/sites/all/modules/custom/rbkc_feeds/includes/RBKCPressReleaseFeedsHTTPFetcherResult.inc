<?php

/**
 * @file
 */

/**
 * Class RBKCPressReleaseFeedsHTTPFetcherResult
 *
 * This class calls our modified version of http_request_get which does not pass
 * authentication.
 */
class RBKCPressReleaseFeedsHTTPFetcherResult extends FeedsHTTPFetcherResult {
  public function getRaw() {
    // We need to include original http_request.inc file as other functions in
    // that file are called from rbkc_http_request.inc
    feeds_include_library('http_request.inc', 'http_request');
    $result = rbkc_http_request_get($this->url, NULL, NULL, NULL, $this->timeout);
    if (!in_array($result->code, array(200, 201, 202, 203, 204, 205, 206))) {
      throw new Exception(t('Download of @url failed with code !code.', array('@url' => $this->url, '!code' => $result->code)));
    }
    return $this->sanitizeRaw($result->data);
  }
}