<?php


class HomepageCest
{
    public function _before(AcceptanceTester $I)
    {
    }

    public function _after(AcceptanceTester $I)
    {
    }

    public function checkHomepageDesktop(AcceptanceTester $I) 
    {
        $I->wantTo('Check homepage elements for desktop');
        $I->amOnPage('/');
        $I->resizeWindow(1440, 900);
        $I->see('Welcome to the Royal Borough');
        $I->seeElement('input', ['name' => 'search_keys']);
    }

    public function checkHomepageMobile(AcceptanceTester $I) 
    {
        $I->wantTo('Check homepage elements for mobile');
        $I->amOnPage('/');
        $I->resizeWindow(600, 1200);
        $I->dontSee('Welcome to the Royal Borough');
        $I->dontSeeElement('iframe', ['class'=>'twitter-timeline']);
        $I->seeElement('input', ['name' => 'search_keys']);
    }    
}


