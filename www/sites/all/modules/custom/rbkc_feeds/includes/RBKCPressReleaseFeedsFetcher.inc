<?php

/**
 * @file
 */

/**
 * Class RBKCPressReleaseFeedsFetcher
 *
 * This class allows us to set out own FeedsHTTPFetcherResult which in turn
 * enables us to use our own version of http_request_get().
 */
class RBKCPressReleaseFeedsFetcher extends FeedsHTTPFetcher {
  public function fetch(FeedsSource $source) {
    $source_config = $source->getConfigFor($this);
    if ($this->config['use_pubsubhubbub'] && ($raw = $this->subscriber($source->feed_nid)->receive())) {
      return new FeedsFetcherResult($raw);
    }
    $fetcher_result = new RBKCPressReleaseFeedsHTTPFetcherResult($source_config['source']);
    // When request_timeout is empty, the global value is used.
    $fetcher_result->setTimeout($this->config['request_timeout']);
    return $fetcher_result;
  }

  public function configForm(&$form_state) {
    return array_merge(parent::configForm($form_state), parent::sourceForm($this->config));
  }

  public function configDefaults() {
    return array_merge(parent::configDefaults(), array('source' => ''));
  }
}