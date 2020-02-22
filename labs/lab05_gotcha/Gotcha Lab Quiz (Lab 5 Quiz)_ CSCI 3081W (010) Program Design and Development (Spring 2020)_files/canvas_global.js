////////////////////////////////////////////////////
// DESIGN TOOLS CONFIG                            //
////////////////////////////////////////////////////
// Copyright (C) 2016  Utah State University
var DT_variables = {
    iframeID: '',
    // Path to the hosted USU Design Tools
    path: 'https://designtools.ciditools.com/',
    templateCourse: '57073',
    // OPTIONAL: Button will be hidden from view until launched using shortcut keys
    hideButton: false,
    // OPTIONAL: Limit tools loading by users role
    limitByRole: false, // set to true to limit to roles in the roleArray
    // adjust roles as needed
    roleArray: [
        'student',
        'teacher',
        'admin'
    ],
    // OPTIONAL: Limit tools to an array of Canvas user IDs
    limitByUser: false, // Change to true to limit by user
    // add users to array (Canvas user ID not SIS user ID)
    userArray: [
        '21','24036','131','23863','1544','152','199','126','496576','217','10352','19604','94','181','220210','410189','22669','27'
    
    ]
};

// Run the necessary code when a page loads
$(document).ready(function () {
'use strict';
// This runs code that looks at each page and determines what controls to create
$.getScript(DT_variables.path + 'js/master_controls.js', function () {
    console.log('master_controls.js loaded');
});
});
////////////////////////////////////////////////////
// END DESIGN TOOLS CONFIG                        //
////////////////////////////////////////////////////


////////////////////////////////////////////////////
// PROCTORIO CONFIG                            //
////////////////////////////////////////////////////
// See https://github.com/proctorio/proctorio.github.io
// Step 5
(function(){var a=document.createElement("script"),b=document.head||document.getElementsByTagName("head")[0];a.onload=function(){b.removeChild(a)};a.src="//cdn.proctorio.net/snippets/gbl/canvas-global-embed.min.js";b.appendChild(a)})();

////////////////////////////////////////////////////
// END PROCTORIO CONFIG                        //
////////////////////////////////////////////////////