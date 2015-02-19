<%@ Page Language="C#" AutoEventWireup="true" Trace="false" CodeFile="details.aspx.cs"
    Inherits="details" %>

<!DOCTYPE html>
<html class="" lang="en">
<head id="Template_Head1">
    <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1" />
    <meta charset="utf-8" />
    <title>Planning Search</title>
    <!-- Define a viewport to mobile devices to use - telling the browser to assume that the page is as wide as the device (width=device-width) and setting the initial page zoom level to be 1 (initial-scale=1.0) -->
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <!-- Add normalize.css which enables browsers to render all elements more consistently and in line with modern standards as it only targets particular styles that need normalizing -->
    <!-- Include the site stylesheet -->

    <script src="/js/refresh/modernizr.custom.03949.js" type="text/javascript"></script>

    <!--  <link href="../../templates/default/css/system/refresh/normalize.css" rel="stylesheet" media="all" />-->
    <!-- <link href="../../templates/default/css/system/refresh/global.css" rel="stylesheet" media="all" /> -->
    <link rel="stylesheet" type="text/css" href="../../templates/default/css/system/refresh/customfonts.css" />
    <link href="../../templates/default/css/system/refresh/globalServiceMenu.css" rel="stylesheet"
        media="all" />
    <link href="../../templates/default/css/system/refresh/refresh.css" rel="stylesheet"
        media="all" />
    <link type="text/css" rel="stylesheet" href="css/responsive-tabs.css" />
    <link type="text/css" rel="stylesheet" href="css/style.css" />
    <link type="text/css" rel="stylesheet" href="css/tablescroll.css" />

    <script type="text/javascript">        document.documentElement.className = "has-js"</script>

    <!--[if lt IE 9]>
<script src="/js/refresh/html5_shiv.js" type="text/javascript"></script>
       
<![endif]-->

    <script type="text/javascript" src="/js/refresh/pdf.js"></script>

    <script type="text/javascript" src="/js/sitestat-loading1.js"></script>

    <meta name="keywords" content="planning Search" />
    <meta name="description" content="planning Search" />
    <style type="text/css">
        .contactTeamSmall
        {
            width: 250px;
        }
        .backbutton
        {
            display: block;
            background-color: #4699be;
            background-image: url('/images/refresh/contact-chevron-back.png');
            background-repeat: no-repeat;
            background-position: 5% center;
            -webkit-border-radius: 3px 3px 3px 3px;
            -moz-border-radius: 3px 3px 3px 3px;
            border-radius: 3px 3px 3px 3px;
            padding: 9px 35px 10px 13px;
            margin-bottom: 32px;
            margin-bottom: 2em;
            color: #FFF;
            font-size: 13px;
            font-size: .8125rem; /* 13/16 = .8125; */
            line-height: 18px;
            font-weight: 700;
            -webkit-text-stroke-width: 0;
        }
        .backbutton:hover
        {
            border-bottom: none;
            background-color: #377A95;
        }
    </style>
</head>
<!--[if IE 7]>         <body class="lt-ie9 lt-ie8"> <![endif]-->
<!--[if IE 8]>         <body class="lt-ie9"> <![endif]-->
<!--[if gt IE 8]><!-->
<body>
    <!--<![endif]-->
    <div class="outerWrapper">
        <div class="betaBanner ">
            <div class="innerPadded">
                <p class="floatLeft">
                    This is our Beta website - <span class="beta-feedback">we're keen to have <a href="https://www.eforms.rbkc.gov.uk/default.aspx/RenderForm/?F.Name=s1doma5TEed">
                        your feedback</span></a></p>
            </div>
            <!-- end innerPadded -->
        </div>
        <!-- end betaBanner -->
        <!-- end betaBanner -->
        <!-- The page header typically contains items such as your site heading, logo and possibly the main site navigation -->
        <!-- ARIA: the landmark role "banner" is set as it is the prime heading or internal title of the page -->
        <div class="headerGlobal" role="banner">
            <div class="innerPadded">
                <a class="logo" href="http://www.rbkc.gov.uk" alt="The Royal Borough of Kensington and Chelsea">
                    The Royal Borough of Kensington and Chelsea </a>
                <div class="menu">
                    <ul>
                        <li class="menu-link"><a href="#" title="Services">Services</a></li>
                        <li><a href="https://www.rbkc.gov.uk/myrbkc/login.aspx" title="MyRBKC">MyRBKC</a></li>
                        <li><a href="http://www.rbkc.gov.uk/councilanddemocracy.aspx" title="Council">Council</a></li>
                        <li><a href="http://www.rbkc.gov.uk/leisureandlibraries/popularlocalmaps.aspx" title="Maps">
                            Maps</a></li>
                    </ul>
                </div>
                <!--end menu -->
                <!--end navMain -->
                <div class="search">
                    <a href="#"></a>
                </div>
                <!--end search -->
                <div class="search_full">
                    <form action="/asp-app-to-aspx-search.aspx" method="post">
                    <input type="hidden" name="currentchannel" id="Hidden1" value="" />
                    <input id="Hidden2" name="DestPage" type="hidden" value="/systempages/search.aspx" />
                    <div style="display: none">
                        <label for="hiddenText">
                            hidden text</label><input type="text" name="hiddenText" id="Text2" /></div>
                    <div id="searchbox" class="form">
                        <p>
                            <label class="rm" for="Template_ctl16_sb_q">
                                Search</label><input name="sb_q" type="text" id="sb_q" accesskey="4" onfocus="clearField(this)"
                                    placeholder="Enter search terms..." /><input type="submit" name="Template$ctl16$sb_btn"
                                        value="Search" id="sb_btn" class="submit" /></p>
                    </div>
                    <p>
                        <a title="Advanced Search" href="/systempages/search.aspx?advanced=1">Advanced Search</a></p>
                    </form>
                </div>
                <!-- end search_full -->
            </div>
            <!-- end innerPadded -->
        </div>
        <!-- end headerGlobal -->
        <!-- New search and menu -->
        <div class="search-expand hide">
            <div class="search_full">
                <!-- insert SearchBoxControlMobile -->
                <form action="/asp-app-to-aspx-search.aspx" method="post">
                <input type="hidden" name="currentchannel" id="currentchannel" value="" />
                <input id="DestPage" name="DestPage" type="hidden" value="/systempages/search.aspx" />
                <div style="display: none">
                    <label for="hiddenText">
                        hidden text</label><input type="text" name="hiddenText" id="Text1" /></div>
                <label class="rm" for="sb_q_mob">
                    Search</label><div class="search_full_text">
                        <input name="sb_q_mob" type="text" id="sb_q_mob" accesskey="4" onfocus="clearField(this)"
                            placeholder="Enter search terms..." /></div>
                <input type="submit" name="sb_btn_mob" value="Search" id="sb_btn_mob" class="submit" />
                </form>
                <!-- end SearchBoxControlMobile -->
            </div>
        </div>
        <!-- </form> -->
        <!-- end search-expand -->
        <div class="serviceMenu hide">
            <ul class="serviceMenu-mobile innerNoPadding">
                <li><a href="http://www.rbkc.gov.uk/services.aspx" title="Services">Services</a></li>
                <li><a href="http://www.rbkc.gov.uk/councilanddemocracy.aspx" title="Council">Council</a></li>
                <li><a href="http://www.rbkc.gov.uk/leisureandlibraries/popularlocalmaps.aspx" title="Maps">
                    Maps</a></li>
                <li><a href="https://www.rbkc.gov.uk/myrbkc/login.aspx" title="MyRBKC">MyRBKC</a></li>
            </ul>
            <div class="serviceMenu-desktop innerPadded">
                <ul>
                    <li><a href="http://www.rbkc.gov.uk/environmentandtransport/parking.aspx" title="Parking, transport and streets">
                        Parking, transport and streets</a></li>
                    <li><a href="http://www.rbkc.gov.uk/environmentandtransport/domesticrecyclingandrubbish.aspx"
                        title="Bins and recycling">Bins and recycling</a></li>
                    <li><a href="http://www.rbkc.gov.uk/planningandbuildingcontrol.aspx" title="Planning">
                        Planning</a></li>
                    <li><a href="http://www.rbkc.gov.uk/leisureandlibraries/libraries.aspx" title="Libraries">
                        Libraries</a></li>
                    <li><a href="http://www.rbkc.gov.uk/councilanddemocracy/counciltax.aspx" title="Council tax">
                        Council tax</a></li>
                    <li><a href="http://www.rbkc.gov.uk/communityandlocallife/registrarsservices.aspx"
                        title="Births, deaths and marriages">Births, deaths and marriages</a></li>
                </ul>
                <ul>
                    <li><a href="http://www.rbkc.gov.uk/educationandlearning.aspx" title="Children and education">
                        Children and education</a></li>
                    <li><a href="http://www.rbkc.gov.uk/leisureandlibraries.aspx" title="Leisure and culture">
                        Leisure and culture</a></li>
                    <li><a href="http://www.rbkc.gov.uk/leisureandlibraries/parksandgardens.aspx" title="Parks and ecology">
                        Parks and ecology</a></li>
                    <li><a href="http://www.rbkc.gov.uk/housing.aspx" title="Housing">Housing</a></li>
                    <li><a href="http://www.rbkc.gov.uk/jobs.aspx" title="Jobs">Jobs</a></li>
                    <li><a href="http://www.rbkc.gov.uk/healthandsocialcare.aspx" title="Health and social care">
                        Health and social care</a></li>
                </ul>
                <ul>
                    <li><a href="http://www.rbkc.gov.uk/environmentandtransport/licensing.aspx" title="Licensing">
                        Licensing</a></li>
                    <li><a href="http://www.rbkc.gov.uk/businessandenterprise.aspx" title="Business and enterprise">
                        Business and enterprise</a></li>
                    <li><a href="http://www.rbkc.gov.uk/environmentandtransport.aspx" title="Environment">
                        Environment</a></li>
                    <li><a href="http://www.rbkc.gov.uk/adviceandbenefits.aspx" title="Jobs">Advice and
                        benefits</a></li>
                    <li><a href="http://www.rbkc.gov.uk/communityandlocallife.aspx" title="Community and local life">
                        Community and local life</a></li>
                    <li><a href="http://www.rbkc.gov.uk/newsroom.aspx" title="Newsroom">Newsroom</a></li>
                </ul>
                <div class="serviceMenu-close">
                    <p>
                        <a>Close menu</a></p>
                </div>
            </div>
            <!-- end serviceMenu-desktop -->
        </div>
        <!-- end serviceMenu -->
        <!-- end new search and menu -->
        <!-- If you want to use an element as a wrapper, i.e. for styling only, then <div> is still the element to use -->
        <div class="backgroundRibbon">
            <div class="innerNoPadding breadcrumb">
                <ol>
                    <!--KR Developer note - set HideHiddenPages to true once live-->
                    <li><a href="/default.aspx" title="Home page">Home page</a></li>
                    <li><strong><a href="/planningandbuildingcontrol.aspx" title="Planning and Building Control">
                        Planning and Building Control</a> </strong></li>
                    <li>Planning search</li>
                </ol>
            </div>
            <!-- end innerNoPadding breadcrumb-->
            <main role="main">
             <!-- The <section> element can be used to enclose content that comes under a related heading.
    NOTE: The <section> element can contain <article> elements and vice versa, if you think the content warrants it. -->
    <!--<section>-->
    
    	<div class="innerNoPadding">
			   <h1>Planning search</h1>
		</div>
				
				<!-- The <main> element is used to enclose the main content, i.e. that which contains the central topic of a document -->
                <!-- ARIA: the landmark role "main" is added here as it contains the main content of the document, and it is recommended to add it to the
                <main> element until user agents implement the required role mapping. -->
				
				<div class="content">
                       <!--  floated left.  Uncleared float defines bottom of ribbon graphic -->
                       <div class="content-inner innerPadded">
                       <!-- unfloated, centered div added for stability - stops any non-floated elements being sucked into the ribbon background -->

	
				
				<div class="row">
                    <div class="col12">
                    
						<form id="recordDetailsPage" runat="server" method="post" class="rbkc-form">
						<asp:PlaceHolder runat="server" ID="hiddenFields" />
						
						<p><asp:Label runat="server" ID="recordNotFound" /></p>
						<p>
							<asp:HyperLink runat="server" Text="Back to search results" ID="backToResults" />

							<asp:Label runat="server" ID="backToResultsLabel" /></p>
							<div id="tabs" runat="server">
							<div id="horizontalTab" >
								<ul class="tabMenu">
									<li><a href="#tabs-planning-1"><span runat="server" id="TabApplications" title="Current application details including the case reference number, site address, applicant's/agent's name and address and a brief description of the proposal.">
										Details</span></a></li>
									<li><a href="#tabs-planning-2"><span runat="server" id="TabAppeals" title="Appeals against decisions that have been refused.">
										Decision</span></a></li>
									<li><a href="#tabs-planning-3"><span runat="server" id="Span1" title="Appeals against decisions that have been refused.">
										Appeal</span></a></li>
									<li><a href="#tabs-planning-4"><span runat="server" id="Span2" title="Appeals against decisions that have been refused.">
										Contact</span></a></li>
									<li><a href="#tabs-planning-5"><span runat="server" id="Span3" title="Appeals against decisions that have been refused.">
										Comment</span></a></li>
                                    <li><a href="#tabs-planning-6"><span runat="server" id="Span4" title="Appeals against decisions that have been refused.">
										Documents</span></a></li>
								</ul>
								<div id="tabs-planning-1">
								<h2>Property details</h2>

						<table id="property-details" class="details">
	
							<tr>
								<th>
									Case reference:
								</th>
								<td>
									<% Response.Write(CaseReference); %>
								</td>
							</tr>
							<tr>
								<th>
									Address:
								</th>
								<td>
									<% Response.Write(Address); %>
								</td>
							</tr>
							<tr>
								<th>
									Ward:
								</th>
								<td>
									<% Response.Write(Ward); %>
								</td>
							</tr>
							<tr>
								<th>
									Polling district:
								</th>
								<td>
									<% Response.Write(PollingDistrict); %>
								</td>
							</tr>
							<tr>
								<th>
									Listed Building Grade:
								</th>
								<td>
									<% Response.Write(ListedBuildingGrade); %>
								</td>
							</tr>
							<tr>
								<th>
									Conservation area:
								</th>
								<td>
									<% Response.Write(ConservationArea); %>
								</td>
							</tr>
						</table>

						<h2>Applicant details</h2>

						<table id="applicant-details" class="details">
							<tr>
								<th>
									Applicant's name:
								</th>
								<td>
									<% Response.Write(ApplicantsName); %>
								</td>
							</tr>
							<tr>
								<th>
									Contact name:
								</th>
								<td>
									<% Response.Write(ContactName); %>
								</td>
							</tr>
							<tr>
								<th>
									Contact address:
								</th>
								<td>
									<% Response.Write(ContactAddress); %>
								</td>
							</tr>
							<tr>
								<th>
									Contact telephone:
								</th>
								<td>
									<% Response.Write(ContactTelephone); %>
								</td>
							</tr>
						</table>

						<h2>Proposal details</h2>

						<table id="proposal-details" class="details">

							<tr>
								<th>
									Application type:
								</th>
								<td>
									<% Response.Write(ApplicationType); %>
								</td>
							</tr>
							<tr>
								<th>
									Proposed development
								</th>
								<td>
									<% Response.Write(Proposal); %>
								</td>
							</tr>
							<tr>
								<th>
									Date received:
								</th>
								<td>
									<% Response.Write(DateReceived); %>
								</td>
							</tr>
							<tr>
								<th>
									Registration date:
									<br />
									(Statutory start date)
								</th>
								<td>
									<% Response.Write(RegistrationDate); %>
								</td>
							</tr>
							<tr runat="server" id="consultationEnds">
								<th>
									Public consultation ends:
								</th>
								<td>
									<% Response.Write(ConsultationPeriod); %>
								</td>
							</tr>
							<tr>
								<th>
									Application status:
								</th>
								<td>
									<% Response.Write(ApplicationStatus); %>
								</td>
							</tr>
							<tr>
								<th>
									Target date for decision:
								</th>
								<td>
									<% Response.Write(ExpiryDate); %>
								</td>
							</tr>

							</table>



						
						</div> <!-- end tabs-planning-1" -->
								<div id="tabs-planning-2">
						

						<table id="decision-details" class="<% Response.Write(displayClass(FinalDecision)); %>">

							<tr>
								<th>
									Decision:
								</th>
								<td>
									<% Response.Write(FinalDecision); %>
								</td>
							</tr>
							<tr>
								<th>
									Decision date:
								</th>
								<td>
									<% Response.Write(DecisionDate); %>
								</td>
							</tr>
							<tr>
								<th>
									Conditions and reasons:
								</th>
								<td>
									<div id="accordion">

										<% Response.Write(DecisionReasonsConditions); %>
									</div>
								</td>
							</tr>
						</table>

						</div><!-- end tabs-planning-2 -->
						<div id="tabs-planning-3" >


						<table id="appeal-details" class="<% Response.Write(displayClass(AppealReceived)); %>">

							<tr>
								<th>
									Formal reference number:
								</th>
								<td>
									<% Response.Write(AppealRefNo); %>
								</td>
							</tr>
							<tr>
								<th>
									Appeal received:
								</th>
								<td>
									<% Response.Write(AppealReceived); %>
								</td>
							</tr>
							<tr>
								<th>
									Appeal start date:
								</th>
								<td>
									<% Response.Write(AppealStartDate); %>
								</td>
							</tr>
							<tr>
								<th>
									Appeal decision:
								</th>
								<td>
									<% Response.Write(AppealDecision); %>
								</td>
							</tr>
							<tr>
								<th>
									Appeal decision date:
								</th>
								<td>
									<% Response.Write(AppealDecisionDate); %>
								</td>
							</tr>
						</table>

						</div><!-- end tabs-planning-3  -->
						<div id="tabs-planning-4">
	
						<table id="planning-dept-contact" class="details">

							<tr>
								<th>
									Planning case officer:
								</th>
								<td>
									<% Response.Write(CaseOfficer); %>
								</td>
							</tr>
							<tr>
								<th>
									Planning team:
								</th>
								<td>
									<% Response.Write(PlanningTeam); %>
								</td>
							</tr>
						</table>

						</div><!-- end tabs-planning-4 -->
						<div id="tabs-planning-5">
                            <h2>Comment on this application</h2>

									<p runat="server" id="noUserComments">
										There is no public consultation on this application. However, you may submit comments using the form below.
									</p>
									<p runat="server" id="userCommentEnded">
										The consultation period for this application has ended.
									</p>
									<p runat="server" id="userCommentThanks">
										<strong>Thank you for your comments.</strong>
									</p>
									<p runat="server" id="noUserCommentsCON">
										<strong>Applications for details required by conditions are published for information only and not for public consultation.</strong>
									</p>
									<p runat="server" id="noUserCommentsNOT">
										<strong>These notifications are published for information only.  The Council cannot decide whether the development takes place.</strong>
									</p>
									<div id="accordion2" runat="server">
										<!--a href="#section">Comment on this application</a-->
										<div>
											<div runat="server" id="userCommentForm">
												<p>
													<label for="UserComments">
														<span>*</span> Your comments</label><br />
													<asp:TextBox runat="server" ID="UserComments" Rows="6" TextMode="MultiLine" />
													<asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ValidationGroup="UserCommentValidation"
														ControlToValidate="UserComments" ErrorMessage="You haven't written any comments..."
														SetFocusOnError="true" Display="Dynamic" EnableClientScript="true" />
												</p>
												<p>
													<label for="UserName">
														<span>*</span> Your name</label><br />
													<asp:TextBox runat="server" ID="UserName" />
													<asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ValidationGroup="UserCommentValidation"
														ControlToValidate="UserName" ErrorMessage="You haven't told us your name..."
														SetFocusOnError="true" Display="Dynamic" EnableClientScript="true" />
												</p>
												<p>
													<label for="UserPostalAddress">
														<span>*</span> Your postal address</label><br />
													<asp:TextBox runat="server" ID="UserPostalAddress" />
													<asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ValidationGroup="UserCommentValidation"
														ControlToValidate="UserPostalAddress" ErrorMessage="You haven't told us your postal address..."
														SetFocusOnError="true" Display="Dynamic" EnableClientScript="true" />
												</p>
												<p>
													<label for="UserTelephone">
														Your telephone number</label><br />
													<asp:TextBox runat="server" ID="UserTelephone" />
												</p>
												<p>
													<label for="UserEmail">
														Your email address</label><br />
													<asp:TextBox runat="server" ID="UserEmail" />
													<asp:RegularExpressionValidator ID="RegularExpressionValidator1" runat="server" ValidationGroup="UserCommentValidation"
														ControlToValidate="UserEmail" ErrorMessage="That email address doesn't look right. Please check and try again..."
														SetFocusOnError="true" ValidationExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*"
														Display="Dynamic" EnableClientScript="true" />
												</p>
												<p>
													<asp:Button runat="server" ID="btnSendComments" Text="Send comments" OnClick="SendComments_Click" />
												</p>
											</div>
										</div>
									</div>
						
						</div><!-- end tabs-planning-5 -->
						<div id="tabs-planning-6">
						<h2>Documents related to case <% Response.Write(CaseReference); %> </h2>

						<div class="scrollBar">
						<div>
						<asp:Literal id="documentsHTML" runat="server" />
						</div>
						</div><!-- end scrollBar -->
						</div><!-- end tabs-planning-6 -->
						</div><!-- end horizontal tabs -->
						</div><!-- end tabs -->
						</form>
						</div>
	
			
		</div><!-- end row -->
		<div class="row">
		<div class="col12">
		    <a href="#showcommentstop" class="backbutton" id="showcomments" runat="server">Click here to comment on this case</a>
		</div>
		
		</div>
			                       </div>
      <!-- end content-inner innerPadded -->
                    </div>
    <!-- end content  -->



    <!-- ARIA: the landmark role "navigation" is added here as the element contains page navigation -->

    <!-- The <article> element can be used to enclose content that still makes sense on its own and is therefore "reusable" -->
    <!-- <article id="introduction"> -->



</main>
        </div>
        <!-- end backgroundRibbon -->
        <!-- NEW -->
        <div class="footerGlobal" role="contentinfo">
            <div class="innerPadded footer-contents">
                <p class="address">
                    Town Hall, Hornton Street, W8 7NX</p>
                <p>
                    <span class="contactphone">Call on <a href="tel://020-7361-3000">020 7361 3000</a></span><span><a
                        href="https://www.eforms.rbkc.gov.uk/default.aspx/RenderForm/?ID=pk7nHLMgM87&TestFillID=acK2hvH1DVo">Email
                        us</a></span></p>
                <ul>
                    <li><a href="/footerlinks/contactus.aspx" title="Contact us">Contact us</a></li>
                    <li><a href="/footerlinks/privacy.aspx" title="Privacy">Cookies and your privacy</a></li>
                    <li><a href="/footerlinks/termsofuse.aspx" title="Terms of use">Terms of use</a></li>
                </ul>
                <p class="socialMedia">
                    <a href="http://uk.sitestat.com/rbkc/rbkc/s?Twitter&ns_type=clickout" class="socialMedia-Twitter"
                        title="Twitter">Twitter</a> <a href="http://uk.sitestat.com/rbkc/rbkc/s?Facebook&ns_type=clickout"
                            class="socialMedia-Facebook" title="Facebook">Facebook</a> <a href="http://uk.sitestat.com/rbkc/rbkc/s?Youtube&ns_type=clickout"
                                class="socialMedia-YouTube" title="YouTube">YouTube</a>
                </p>
                <!-- Copyright information can be contained within the <small> element. The <time> element is used here to indicate that the '2013' is a date -->
                <p>
                    &copy;
                    <time>1998-2014</time>
                    The Royal Borough of Kensington and Chelsea</p>
            </div>
        </div>
        <!-- end footerGlobal -->
        <!-- Begin Sitestat4 code -->

        <script type="text/javascript">
<!--
            function sitestat(ns_l) {
                ns_l += '&amp;ns__t=' + (new Date()).getTime(); ns_pixelUrl = ns_l;
                ns_0 = document.referrer;
                ns_0 = (ns_0.lastIndexOf('/') == ns_0.length - 1) ? ns_0.substring(ns_0.lastIndexOf('/'), 0) : ns_0;
                if (ns_0.length > 0) ns_l += '&amp;ns_referrer=' + escape(ns_0);
                if (document.images) { ns_1 = new Image(); ns_1.src = ns_l; } else
                    document.write('<img src="' + ns_l + '" width="1" height="1" alt="" />');
            }
            sitestat("http://uk.sitestat.com/rbkc/rbkc/s?planning-building-control.search.default");
//-->
        </script>

        <noscript>
            <div>
                <img src="http://uk.sitestat.com/rbkc/rbkc/s?planning-building-control.search.default"
                    width="1" height="1" alt="" /></div>
        </noscript>
        <!-- End Sitestat4 code -->
        <!-- Begin Sitestat4 Technical code -->

        <script type="text/javascript" src="/sitestat.js"></script>

        <noscript>
            <div>
                &nbsp;</div>
        </noscript>
        <!-- End Sitestat4 Technical code -->
        <!-- Begin Sitestat4 Loadingtime2 code -->

        <script type="text/javascript">            ns_loadingtime2 = (new Date()).getTime();</script>

        <noscript>
            <div>
                &nbsp;</div>
        </noscript>

        <script src="js/jquery-2.1.0.min.js"></script>

        <!-- Responsive Tabs JS -->

        <script src="js/jquery.responsiveTabs.js" type="text/javascript"></script>

        <script type="text/javascript">
            $(document).ready(function() {
                $('#horizontalTab').responsiveTabs({
                    rotate: false,
                    collapsible: true,
                    setHash: true,
                    active: 0
                    //,
                    //disabled: [3, 4]
                });

                $('#start-rotation').on('click', function() {
                    $('#horizontalTab').responsiveTabs('active');
                });
                $('#stop-rotation').on('click', function() {
                    $('#horizontalTab').responsiveTabs('stopRotation');
                });
                $('#start-rotation').on('click', function() {
                    $('#horizontalTab').responsiveTabs('active');
                });
                $('.select-tab').on('click', function() {
                    $('#horizontalTab').responsiveTabs('activate', $(this).val());
                });

                //BEGIN code to add click to showcommments link
                $('#showcomments').on('click', function() {
                    $('#horizontalTab').responsiveTabs('activate', 4);
                });
                //END  code to add click to showcommments link

            });
        </script>

        <!-- End Sitestat4 Loadingtime2 code -->

        <script src="/js/refresh/menu.js" type="text/javascript"></script>

        <script src="/js/refresh//pdf_accordion.js" type="text/javascript"></script>

        <script src="/js/refresh//show_hide_RHC_12_03_14.js" type="text/javascript"></script>

        <script src="/js/refresh/childParent.js" type="text/javascript"></script>

    </div>
    <!-- end outerWrapper -->
</body>
</html>
