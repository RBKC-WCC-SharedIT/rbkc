<?php


class SearchCest
{
    public function _before(AcceptanceTester $I)
    {
    }

    public function _after(AcceptanceTester $I)
    {
    }

    public function checkSearchBoxOnHomepage(AcceptanceTester $I)
    {
        $I->wantTo('Check home page search box exists and works.');
        $I->amOnPage('/');

        $I->seeElement('input', ['name' => 'search_keys']);        

        $I->fillField(['name' => 'search_keys'], 'contact');
        $I->click('Search');
        $I->seeCurrentUrlEquals('/gsearch/contact');
    }

    /**
     * Run on test, dev, stage and prod only (not on local)
     * @env test
     * @env dev
     * @env stage
     * @env prod
     */
    public function checkSearchIsWorking(AcceptanceTester $I)
    {
        $I->wantTo('Check search is working.');
        $I->amOnPage('/gsearch/contact');
        $I->see('Search results');
    }

    public function checkSearchBoxLowerLevelDesktop(AcceptanceTester $I)
    {
        $I->wantTo('Check search box exists on lower level pages.');
        $I->amOnPage('/licensing-information/licensing');
        $I->resizeWindow(1440, 900);

        $I->seeElement('input', ['name' => 'search_keys']);        

        $I->fillField(['name' => 'search_keys'], 'contact');
        $I->click('Search');
        $I->seeCurrentUrlEquals('/gsearch/contact');
    }

    public function checkSearchBoxLowerLevelMobile(AcceptanceTester $I)
    {
        $I->wantTo('Check search box exists on lower level pages on mobile.');
        $I->amOnPage('/licensing-information/licensing');
        $I->resizeWindow(600, 1200);

        $I->seeElement('button', ['id' => 'openSearch']);  
        
        $I->click(['id' => 'openSearch']);      
        $I->seeElement('input', ['name' => 'search_keys']);

        $I->fillField(['name' => 'search_keys'], 'contact');
        $I->click('Search');
        $I->seeCurrentUrlEquals('/gsearch/contact');        
    }

}
