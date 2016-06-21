<?php


class HomepageCarouselCest
{
    public function _before(AcceptanceTester $I)
    {
    }

    public function _after(AcceptanceTester $I)
    {
    }

    public function checkCarouselExists(AcceptanceTester $I)
    {
        $I->wantTo('Check that the carousel exists on the homepage');
        $I->amOnPage('/');
        $I->see('Local life in the Royal Borough of Kensington and Chelsea');
        $I->seeElement('div', ['class'=>'slick-list draggable']);

    } 

    public function checkCarouselScrollNextDesktop(AcceptanceTester $I)
    {
        $I->wantTo('Check the carousel Next button');
        $I->amOnPage('/');    
        $elementsOriginal = $I->grabMultiple('.slick-active'); // grab all the visible items
        $I->click('Next');
        $elementsAfterNext = $I->grabMultiple('.slick-active');
        $I->assertSame($elementsAfterNext[0], $elementsOriginal[1]);
    }    

    public function checkCarouselScrollPrevDesktop(AcceptanceTester $I)
    {
        $I->wantTo('Check the carousel Previous button');
        $I->amOnPage('/');    
        $elementsOriginal = $I->grabMultiple('.slick-active'); // grab all the visible items
        $I->click('Previous');
        $I->wait(1); // wait for transition to finish 
        $elementsAfterPrev = $I->grabMultiple('.slick-active');
        $I->assertSame($elementsAfterPrev[1], $elementsOriginal[0]);
    }      

    public function checkCarouselScrollNextMobile(AcceptanceTester $I)
    {
        $I->wantTo('Check the carousel Next button, for mobile');
        $I->amOnPage('/');   
        $I->resizeWindow(600, 1200);
        $elementsOriginal = $I->grabMultiple('.slick-active'); // grab all the visible items
        $I->click('Next');
        $elementsAfterNext = $I->grabMultiple('.slick-active');
        $I->assertNotEmpty($elementsAfterNext[0]);
        $I->assertNotSame($elementsAfterNext[0], $elementsOriginal[0]);
    }    

    public function checkCarouselScrollPrevMobile(AcceptanceTester $I)
    {
        $I->wantTo('Check the carousel Previous button, for mobile');
        $I->amOnPage('/');  
        $I->resizeWindow(600, 1200);          
        $elementsOriginal = $I->grabMultiple('.slick-active'); // grab all the visible items
        $I->click('Previous');
        $I->wait(1); // wait for transition to finish 
        $elementsAfterPrev = $I->grabMultiple('.slick-active');        
        $I->assertNotEmpty($elementsAfterPrev[0]);
        $I->assertNotSame($elementsAfterPrev[0], $elementsOriginal[0]);
    }          
}

