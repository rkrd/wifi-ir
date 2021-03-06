/*
<script type="text/javascript">
(function(a,b,c){if(c in b&&b[c]){var d,e=a.location,f=/^(a|html)$/i;a.addEventListener("click",function(a){console.debug("clllickl");d=a.target;while(!f.test(d.nodeName))d=d.parentNode;"href"in d&&(d.href.indexOf("http")||~d.href.indexOf(e.host))&&(a.preventDefault(),e.href=d.href)},!1)}})(document,window.navigator,"standalone")</script>
*/
char head_html[] = R"=====(
    <head>
        <title>MinRic Remote</title>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
        <meta name="apple-mobile-web-app-title" content="MinRic Remote">
        <meta name="viewport" content="minimal-ui, user-scalable=no">
        <meta content="yes" name="apple-mobile-web-app-capable" />
        <script>
            // Source: https://gist.github.com/irae/1042167
            (function(a,b,c){if(c in b&&b[c]){var d,e=a.location,f=/^(a|html)$/i;a.addEventListener("click",function(a){d=a.target;while(!f.test(d.nodeName))d=d.parentNode;"href"in d&&(d.href.indexOf("http")||~d.href.indexOf(e.host))&&(a.preventDefault(),e.href=d.href)},!1)}})(document,window.navigator,"standalone");

            // Disable scrolling on page.
            document.ontouchmove = function(event){
                event.preventDefault();
            }
</script>
        <style>
html, body {
    width: 100%;
    height: 100%;
    padding: 0;
    margin: 0;
}
body {
    background: linear-gradient(to top, rgba(0,0,0,.5), rgba(0,0,0,0));
}
.container {
    height: 100%;
}
.gradient {
    background-color: #222937;
    height: 100%;
    min-height: 100%;
    width: 100%;
    margin: 0;
}
.smallbar {
    border-bottom-style: solid;
    border-color: rgba(255, 255, 255, .2);
    height: 10%;
    display: flex;
    justify-content: center;
    align-items: center;
}

.bigbar {
    height: 50%;
    border-bottom-style: solid;
    border-color: rgba(255, 255, 255, .2);
    display: flex;
}

.color-buttons {
    margin: auto;
}
.color-buttons div {
    width: 140px;
    height: 34px;
    border-radius: 17px;
    opacity: .8;
}
.color-buttons td {
    padding-left: 10px;
    padding-right: 10px;
}
#red {
    background-color: #FE3824;
}
#green {
    background-color: #44DB5E;
}
#yellow {
    background-color: #FFCD00;
}
#blue {
    background-color: #54C7FC;
}

#channels, #smart-area, #volume-area {
    margin-left: 15%;
    margin-right: 15%;
}
#play-area {
    margin-left: 20%;
    margin-right: 15%;
}
#channel-left {
    width: 20%;
}
#channel-mid {
    width: 60%;
}
#channel-right {
    width: 20%;
}
#channel-left svg{
    width: 55%;
    margin: auto;
    float: left;
}
#channel-right svg{
    width: 55%;
    margin: auto;
    float: right;
}
#smart-left {
    width: 20%;
}
#smart-mid {
    width: 60%;
    align-content: center;
}
#smart-right {
    width: 20%;
}
#smart-left svg{
    width: 50%;
    margin: auto;
    float: left;
}
#smart-mid svg{
    width: 20%;
    margin: auto;
    display: block;

}
#smart-right svg{
    width: 70%;
    margin: auto;
    float: right;
}
#play-left {
    width: 25%;
}
#play-mid {
    width: 25%;
    align-content: center;
}
#play-mid2 {
    width: 25%;
    align-content: center;
}
#play-right {
    width: 25%;
}
#play-left svg{
    width: 65%;
    transform: rotate(180deg);
}
#play-mid svg{
    width: 60%;
}
#play-mid2 svg{
    width: 55%;
    transform: rotate(90deg);
}
#play-right svg{
    width: 65%;
}
.green-icons {
    fill: #58B29A;
}
.white-icons {
    fill: #FFF;
    opacity: .8;
}
h1 {
    font-family: Helvetica;
    text-transform:uppercase;
    color:white;
    opacity: .8;
    font-weight: 300;
    font-size: 3.2em;
    text-align: center;
}
a {
    text-decoration: none;
}
h2 {
    font-family: Helvetica;
    text-transform:uppercase;
    color:white;
    font-weight: 500;
    font-size: 3.6em;
    text-align: center;
}
#on-area {
    width: 25%;
}
#power svg {
    width: 100px;
    float: left;
    margin-top: 55%;
}
#arrow-empty {
    width: 25%;
}
#arrow-area {
    width: 50vw;
    height: 50vw;
    margin: auto;

    border-radius: 50%;
    border-style: solid;
    border-color: rgba(255, 255, 255, .2);
}
#arrows {
    width: 100%;
    height: 100%;
}
#arrows tr {
    height: 33%;
}
#arrows svg {
    width: 100px;
    display: block;
}
#arrow-up svg {
    transform: rotate(270deg);
    margin: 15% auto;

}
#arrow-left svg {
    transform: rotate(180deg);
    margin: auto;
}
#arrow-ok {
    border-radius: 100%;
    background-color: #58B29A;
}
#arrow-right svg {
    margin: auto;
}
#arrow-down svg {
    transform: rotate(90deg);
    margin: auto;
}
#mute svg {
    width: 100px;
    display: block;
    margin: auto;
}

        </style>
    </head>
)=====";

char body_html[] = R"=====(
    <body>
    <div class="container">
    <div class="gradient">
           <div class="smallbar">
               <div class="color-buttons">
                <table class="color-buttons">
                <tr>
                    <td><a href="/RED"><div id="red"></div></a></td>
                    <td><a href="/GREEN"><div id="green"></div></a></td>
                    <td><a href="/YELLOW"><div id="yellow"></div></a></td>
                    <td><a href="/BLUE"><div id="blue"></div></a></td>
                </tr>
            </table>
               </div>
            </div><!-- color -->

        <div class="smallbar">
            <table id="channels">
                <tr>
                    <td id="channel-left"><a href="/CHAN_DOWN"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 42 42" style="enable-background:new 0 0 42 42;" xml:space="preserve"
                    class="green-icons">
                    <rect y="19" width="42" height="4" /></svg></a></td>

                    <td id="channel-mid"><h1>Channel</h1></a></td>

                    <td id="channel-right"><a href="/CHAN_UP"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 42 42" style="enable-background:new 0 0 42 42;" xml:space="preserve"
                    class="green-icons">
                    <polygon points="42,19 23,19 23,0 19,0 19,19 0,19 0,23 19,23 19,42 23,42 23,23 42,23 "/></svg></a></td>
                </tr>
            </table><!-- channels -->
       </div>

       <div class="bigbar">
           <div id="arrow-empty"></div><!-- arrow-empty -->

            <div id="arrow-area">
                <table id="arrows">
                    <tr>
                        <td></td>

                        <td id="arrow-up">
                            <a href="/UP"><svg version="1.1" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 129 129" xmlns:xlink="http://www.w3.org/1999/xlink" enable-background="new 0 0 129 129"
                            class="white-icons">
                            <g>
                             <path d="m40.4,121.3c-0.8,0.8-1.8,1.2-2.9,1.2s-2.1-0.4-2.9-1.2c-1.6-1.6-1.6-4.2 0-5.8l51-51-51-51c-1.6-1.6-1.6-4.2 0-5.8 1.6-1.6 4.2-1.6 5.8,0l53.9,53.9c1.6,1.6 1.6,4.2 0,5.8l-53.9,53.9z"/>
                             </g></svg></a>
                        </td>
                     </tr>

                     <tr>
                        <td id="arrow-left"><a href="/LEFT"><svg version="1.1" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 129 129" xmlns:xlink="http://www.w3.org/1999/xlink" enable-background="new 0 0 129 129"
                        class="white-icons">
                        <g>
                         <path d="m40.4,121.3c-0.8,0.8-1.8,1.2-2.9,1.2s-2.1-0.4-2.9-1.2c-1.6-1.6-1.6-4.2 0-5.8l51-51-51-51c-1.6-1.6-1.6-4.2 0-5.8 1.6-1.6 4.2-1.6 5.8,0l53.9,53.9c1.6,1.6 1.6,4.2 0,5.8l-53.9,53.9z"/>
                         </g></svg></a></td>

                         <td id="arrow-ok"><a href="/OK"><div id="ok-button"><h2>OK</h2></div></a></td>

                         <td id="arrow-right"><a href="/RIGHT"><svg version="1.1" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 129 129" xmlns:xlink="http://www.w3.org/1999/xlink" enable-background="new 0 0 129 129"
                        class="white-icons">
                        <g>
                         <path d="m40.4,121.3c-0.8,0.8-1.8,1.2-2.9,1.2s-2.1-0.4-2.9-1.2c-1.6-1.6-1.6-4.2 0-5.8l51-51-51-51c-1.6-1.6-1.6-4.2 0-5.8 1.6-1.6 4.2-1.6 5.8,0l53.9,53.9c1.6,1.6 1.6,4.2 0,5.8l-53.9,53.9z"/>
                         </g></svg></a></td>
                    </tr>

                    <tr>
                        <td></td>

                        <td id="arrow-down"><a href="/DOWN"><svg version="1.1" xmlns="http://www.w3.org/2000/svg" viewBox="0 0 129 129" xmlns:xlink="http://www.w3.org/1999/xlink" enable-background="new 0 0 129 129"
                        class="white-icons">
                        <g>
                         <path d="m40.4,121.3c-0.8,0.8-1.8,1.2-2.9,1.2s-2.1-0.4-2.9-1.2c-1.6-1.6-1.6-4.2 0-5.8l51-51-51-51c-1.6-1.6-1.6-4.2 0-5.8 1.6-1.6 4.2-1.6 5.8,0l53.9,53.9c1.6,1.6 1.6,4.2 0,5.8l-53.9,53.9z"/>
                         </g></svg></a></td>

                         <td></td>
                    </tr>
                </table>
            </div><!-- arrow-area -->

            <div id="on-area">
                        <a id="power" href="/POWER"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                            viewBox="0 0 57 57" style="enable-background:new 0 0 57 57;" xml:space="preserve"
                            class="green-icons">
                            <g>
                            <path d="M28.5,29c1.104,0,2-0.896,2-2V2c0-1.104-0.896-2-2-2s-2,0.896-2,2v25C26.5,28.104,27.396,29,28.5,29z"/>
                            <path d="M54.418,29.025c-0.007-0.091-0.013-0.183-0.021-0.274c-0.86-10.027-7.407-18.423-16.403-21.955
                            c-0.092-0.036-0.182-0.073-0.274-0.108c-0.584-0.221-1.177-0.422-1.78-0.602c-0.044-0.013-0.086-0.031-0.13-0.044
                            c-0.012-0.003-0.024,0-0.036-0.003C34.551,5.683,33.29,5.419,32,5.244v4.038C42.473,10.963,50.5,20.06,50.5,31
                            c0,12.131-9.869,22-22,22s-22-9.869-22-22c0-10.94,8.027-20.037,18.5-21.719V5.243c-1.278,0.174-2.529,0.435-3.742,0.786
                            c-0.012,0.003-0.025,0-0.037,0.003c-0.047,0.014-0.091,0.032-0.137,0.046c-0.604,0.179-1.198,0.379-1.783,0.601
                            c-0.09,0.034-0.178,0.071-0.268,0.106c-1.255,0.491-2.463,1.076-3.614,1.748c-0.01,0.006-0.02,0.011-0.031,0.017
                            C8.292,12.705,3.344,20.123,2.603,28.748c-0.008,0.091-0.014,0.183-0.021,0.275C2.533,29.676,2.5,30.334,2.5,31
                            c0,14.359,11.641,26,26,26s26-11.641,26-26C54.5,30.335,54.467,29.677,54.418,29.025z"/></g></svg></a>
            </div><!-- on-area -->

       </div> <!-- remote-area -->

       <div class="smallbar">
            <table id="smart-area">
                <tr>
                    <td id="smart-left"><a href="/EXIT"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 32.526 32.526" style="enable-background:new 0 0 32.526 32.526;" xml:space="preserve"
                    class="white-icons">
                    <polygon points="32.526,2.828 29.698,0 16.263,13.435 2.828,0 0,2.828 13.435,16.263 0,29.698 2.828,32.526 16.263,19.091
                    29.698,32.526 32.526,29.698 19.091,16.263 "/></svg></a></td>

                    <td id="smart-mid"><a href="/BACK"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    width="156.199px" height="156.199px" viewBox="0 0 156.199 156.199" style="enable-background:new 0 0 156.199 156.199;"
                    xml:space="preserve"
                    class="white-icons">
                    <path d="M102.496,45.204h-2.499v-0.012l-77.613-0.368l32.958-32.959l-8.277-8.28L0,50.65l47.882,47.889
                    l8.28-8.28l-33.719-33.73l71.642,0.346v0.04h8.417c23.151,0,41.993,18.838,41.993,41.997c0,23.151-18.842,41.992-41.993,41.992H0
                    v11.711h102.496c29.613,0,53.703-24.09,53.703-53.703C156.199,69.293,132.109,45.204,102.496,45.204z"/></svg></a></td>

                    <td id="smart-right"><a href="/HOME"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 58.365 58.365" style="enable-background:new 0 0 58.365 58.365;" xml:space="preserve"
                    class="green-icons">
                    <path d="M57.863,26.632L29.182,0L0.502,26.632c-0.404,0.376-0.428,1.009-0.052,1.414c0.374,0.404,1.009,0.427,1.413,0.052
                    l4.319-4.011v3.278v31h16v-18c0-3.866,3.134-7,7-7s7,3.134,7,7v18h16v-31v-3.278l4.319,4.011c0.192,0.179,0.437,0.267,0.681,0.267
                    c0.269,0,0.536-0.107,0.732-0.319C58.291,27.641,58.267,27.008,57.863,26.632z"/></svg></a></td>
                </tr>
            </table><!-- small-area -->
           </div>

           <div class="smallbar">
            <table id="play-area">
                <tr>
                    <td id="play-left"><a href="/REWIND"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 57 57" style="enable-background:new 0 0 57 57;" xml:space="preserve"
                    class="white-icons">
                    <path d="M56.575,27.683l-27-19c-0.306-0.216-0.703-0.242-1.036-0.07C28.208,8.784,28,9.127,28,9.5v17.777L1.575,8.694
                    C1.27,8.481,0.872,8.453,0.539,8.625C0.208,8.797,0,9.14,0,9.513v37.975c0,0.373,0.208,0.716,0.539,0.888
                    C0.685,48.45,0.843,48.487,1,48.487c0.202,0,0.403-0.062,0.575-0.182L28,29.723V47.5c0,0.373,0.208,0.716,0.539,0.888
                    C28.685,48.463,28.843,48.5,29,48.5c0.202,0,0.404-0.062,0.575-0.183l27-19C56.842,29.131,57,28.825,57,28.5
                    S56.842,27.869,56.575,27.683z M2,45.562V11.439L26.262,28.5L2,45.562z M30,45.573V11.427L54.263,28.5L30,45.573z"/></svg></a></td>

                    <td id="play-mid"><a href="/PLAY"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 41.999 41.999" style="enable-background:new 0 0 41.999 41.999;" xml:space="preserve"
                    class="green-icons">
                    <path d="M36.068,20.176l-29-20C6.761-0.035,6.363-0.057,6.035,0.114C5.706,0.287,5.5,0.627,5.5,0.999v40
                    c0,0.372,0.206,0.713,0.535,0.886c0.146,0.076,0.306,0.114,0.465,0.114c0.199,0,0.397-0.06,0.568-0.177l29-20
                    c0.271-0.187,0.432-0.494,0.432-0.823S36.338,20.363,36.068,20.176z M7.5,39.095V2.904l26.239,18.096L7.5,39.095z"/></svg></a></td>

                    <td id="play-mid2"><a href="/PAUSE"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 36 36" style="enable-background:new 0 0 36 36;" xml:space="preserve"
                    class="white-icons">
                    <g>
                    <rect y="12" width="36" height="2"/>
                    <rect y="22" width="36" height="2"/>
                    </g></svg></a></td>

                    <td id="play-right"><a href="/FORWARD"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 57 57" style="enable-background:new 0 0 57 57;" xml:space="preserve"
                    class="white-icons">
                    <path d="M56.575,27.683l-27-19c-0.306-0.216-0.703-0.242-1.036-0.07C28.208,8.784,28,9.127,28,9.5v17.777L1.575,8.694
                    C1.27,8.481,0.872,8.453,0.539,8.625C0.208,8.797,0,9.14,0,9.513v37.975c0,0.373,0.208,0.716,0.539,0.888
                    C0.685,48.45,0.843,48.487,1,48.487c0.202,0,0.403-0.062,0.575-0.182L28,29.723V47.5c0,0.373,0.208,0.716,0.539,0.888
                    C28.685,48.463,28.843,48.5,29,48.5c0.202,0,0.404-0.062,0.575-0.183l27-19C56.842,29.131,57,28.825,57,28.5
                    S56.842,27.869,56.575,27.683z M2,45.562V11.439L26.262,28.5L2,45.562z M30,45.573V11.427L54.263,28.5L30,45.573z"/></svg></a></td>
                </tr>
            </table>
               </div><!-- play-area -->


            <div class="smallbar">
            <table id="volume-area">
                <tr>
                    <td id="channel-left"><a href="/VOL_DOWN"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 42 42" style="enable-background:new 0 0 42 42;" xml:space="preserve"
                    class="green-icons">
                    <rect y="19" width="42" height="4" /></svg></a></td>

                    <td id="mute"><a href="/MUTE"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 54 54" style="enable-background:new 0 0 54 54;" xml:space="preserve"
                    class="white-icons">
                    <g>
                    <path d="M46.414,26l7.293-7.293c0.391-0.391,0.391-1.023,0-1.414s-1.023-0.391-1.414,0L45,24.586l-7.293-7.293
                    c-0.391-0.391-1.023-0.391-1.414,0s-0.391,1.023,0,1.414L43.586,26l-7.293,7.293c-0.391,0.391-0.391,1.023,0,1.414
                    C36.488,34.902,36.744,35,37,35s0.512-0.098,0.707-0.293L45,27.414l7.293,7.293C52.488,34.902,52.744,35,53,35
                    s0.512-0.098,0.707-0.293c0.391-0.391,0.391-1.023,0-1.414L46.414,26z"/>
                    <path d="M28.404,4.4c-0.975-0.552-2.131-0.534-3.09,0.044c-0.046,0.027-0.09,0.059-0.13,0.093L11.634,16H1c-0.553,0-1,0.447-1,1v19
                    c0,0.266,0.105,0.52,0.293,0.707S0.734,37,1,37l10.61-0.005l13.543,12.44c0.05,0.046,0.104,0.086,0.161,0.12
                    c0.492,0.297,1.037,0.446,1.582,0.446c0.517-0.001,1.033-0.134,1.508-0.402C29.403,49.035,30,48.005,30,46.844V7.156
                    C30,5.995,29.403,4.965,28.404,4.4z M28,46.844c0,0.431-0.217,0.81-0.579,1.015c-0.155,0.087-0.548,0.255-1,0.026L13,35.556V31
                    c0-0.553-0.447-1-1-1s-1,0.447-1,1v3.996L2,35V18h9v4c0,0.553,0.447,1,1,1s1-0.447,1-1v-4.536l13.405-11.34
                    c0.46-0.242,0.86-0.07,1.016,0.018C27.783,6.347,28,6.725,28,7.156V46.844z"/></g></svg></a></td>

                    <td id="channel-right"><a href="/VOL_UP"><svg version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" x="0px" y="0px"
                    viewBox="0 0 42 42" style="enable-background:new 0 0 42 42;" xml:space="preserve"
                    class="green-icons">
                    <polygon points="42,19 23,19 23,0 19,0 19,19 0,19 0,23 19,23 19,42 23,42 23,23 42,23 "/></svg></a></td>
                </tr>
            </table><!-- volume-area -->
           </div>
    </div> <!-- gradient -->
    </div> <!-- container -->
    </body>
)=====";
