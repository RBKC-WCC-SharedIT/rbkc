<?php 
$I = new AcceptanceTester($scenario);
$I->wantTo('See if this Codeception thing works for me');
$I->amOnPage('/');
$I->seeElement('body');
