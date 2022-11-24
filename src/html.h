const char HTTP_HEADER[] PROGMEM =
    "<head>"
    "<script type='text/javascript' src='/js/jquery-min.js'></script>"
    "<script type='text/javascript' src='/js/bootstrap.min.js'></script>"
    "<script type='text/javascript' src='/js/functions.js'></script>"
    "<script type='text/javascript' src='/js/toast.js'></script>"
    "<script>function logoutButton() {"
    "var xhr = new XMLHttpRequest();"
    "xhr.open('GET', '/logout', true);"
    "xhr.send();"
    "setTimeout(function(){ window.open('/logged-out','_self'); }, 500);"
    "}</script>"
    "<link href='css/required.css' rel='stylesheet' type='text/css' />"
    "<link rel='icon' href='img/logo.png'>"
    "<title>{{pageName}} - ZigStar GW RU</title>"
    " </head>"
    "<body>"
    "<nav class='navbar navbar-expand-lg navbar-light bg-info rounded' style='margin: 10px;'><a class='navbar-brand' href='/'><img src='img/logo.png'/> <strong>ZigStar GW RU</strong>"
    "</a>"
    "<button class='navbar-toggler' type='button' data-toggle='collapse' data-target='#navbarNavDropdown' aria-controls='navbarNavDropdown' aria-expanded='false' aria-label='Toggle navigation'>"
    "<span class='navbar-toggler-icon'></span>"
    "</button>"
    "<div id='navbarNavDropdown' class='collapse navbar-collapse justify-content-md-end'>"
    "<ul class='navbar-nav'>"
    "<li class='nav-item'>"
    "<a class='nav-link' href='/'><i class='glyphicon glyphicon-home'></i>Состояние</a>"
    "</li>"
    "<li class='nav-item dropdown'>"
    "<a class='nav-link dropdown-toggle' href='#' id='navbarDropdown' role='button' data-toggle='dropdown' aria-haspopup='true' aria-expanded='false'><i  class='glyphicon glyphicon-cog'></i>Конфигурация</a>"
    "<div class='dropdown-menu' aria-labelledby='navbarDropdown'>"
    "<a class='dropdown-item' href='/general'><i class='glyphicon glyphicon-list-alt'></i>Основная</a>"
    "<a class='dropdown-item' href='/serial'><i class='glyphicon glyphicon-wrench'></i>Последовательный порт</a>"
    "<a class='dropdown-item' href='/ethernet'><i class='glyphicon glyphicon-globe'></i>Сетевой порт</a>"
    "<a class='dropdown-item' href='/wifi'><i class='glyphicon glyphicon-signal'></i>WiFi</a>"
    "<a class='dropdown-item' href='/mqtt'><i class='glyphicon glyphicon-screenshot'></i>MQTT</a>"
    "</div>"
    "</li>"
    "<li class='nav-item dropdown'>"
    "<a class='nav-link dropdown-toggle' href='#' id='navbarDropdown' role='button' data-toggle='dropdown' aria-haspopup='true' aria-expanded='false'><i  class='glyphicon glyphicon-wrench'></i>Инструменты</a>"
    "<div class='dropdown-menu' aria-labelledby='navbarDropdown'>"
    "<a class='dropdown-item' href='/logs'><i  class='glyphicon glyphicon-transfer'></i>Консоль</a>"
    "<a class='dropdown-item' href='/fsbrowser'><i class='glyphicon glyphicon-floppy-disk'></i>FSbrowser</a>"
    "<a class='dropdown-item' href='/esp_update'><i class='glyphicon glyphicon-open'></i>Обновление ESP32</a>"
    //"<a class='dropdown-item' href='/updates'><i class='glyphicon glyphicon-open'></i>Update Zigbee</a>"
    "<a class='dropdown-item' href='/reboot'><i class='glyphicon glyphicon-repeat'></i>Перезагрузка ESP32</a>"
    "</div>"
    "</li>"
    "<li class='nav-item'>"
    "<a class='nav-link' href='/help'><i class='glyphicon glyphicon-info-sign'></i>Помощь</a>"
    "</li>"
    "{{logoutLink}}"
    "</ul></div>"
    "</nav>";

const char LOGOUT_LINK[] PROGMEM = 
    "<li class='nav-item'>"
    "<a class='nav-link' href='javascript:logoutButton();'><i class='glyphicon glyphicon glyphicon-log-out'></i>Выход</a>"
    "</li>";

const char HTTP_WIFI[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<div id='main' class='col-sm-12'>"
    "<div id='main' class='col-sm-6'><form method='POST' action='saveWifi'>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='wifiEnable' type='checkbox' name='wifiEnable' {{checkedWiFi}}>"
    "<label class='form-check-label' for='wifiEnable'>Включить режим клиента Wi-Fi</label>"
    "</div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='ssid'>SSID</label>"
    "<input class='form-control' id='ssid' type='text' name='WIFISSID' value='{{ssid}}'>"
    "</div>"
    "<div class='form-group'>"
    "<a onclick='scanNetwork();' class='btn btn-warning mb-2'>Сканирование</a>"
    "</div>"
    "<div class='form-group'>"
    "<div id='networks'></div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='pass'>Пароль</label>"
    "<input class='form-control' id='pass' type='password' name='WIFIpassword' value='{{passWifi}}'>"
    "</div>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='dhcpWiFi' type='checkbox' name='dhcpWiFi' {{dchp}}>"
    "<label class='form-check-label' for='dhcpWiFi'>DHCP</label>"
    "</div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='ip'>IP</label>"
    "<input class='form-control' id='ip' type='text' name='ipAddress' value='{{ip}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='mask'>Маска</label>"
    "<input class='form-control' id='mask' type='text' name='ipMask' value='{{mask}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='gateway'>Шлюз</label>"
    "<input type='text' class='form-control' id='gateway' name='ipGW' value='{{gw}}'>"
    "</div>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='disableEmerg' type='checkbox' name='disableEmerg' {{checkedDisEmerg}}>"
    "<label class='form-check-label' for='disableEmerg'><b>Отключить</b> аварийный режим (AP)</label>"
    "</div>"
    "</div>"
    "<button type='submit' class='btn btn-primary mb-2' name='save'>Сохранить</button>"
    "</form>";

const char HTTP_SERIAL[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<div id='main' class='col-sm-12'>"
    "<div id='main' class='col-sm-6'><form method='POST' action='saveSerial'>"

    "<div class='form-group'>"
    "<label for='baud'>Скорость последовательного порта</label>"
    "<select class='form-control' id='baud' name='baud'>"
    "<option value='9600' {{selected9600}}>9600 bauds</option>"
    "<option value='19200' {{selected19200}}>19200 bauds</option>"
    "<option value='38400' {{selected38400}}>38400 bauds</option>"
    "<option value='57600' {{selected57600}}>57600 bauds</option>"
    "<option value='115200' {{selected115200}}>115200 bauds</option>"
    "</select>"
    "</div>"
    "<div class='form-group'>"
    "<label for='port'>Сокет-порт</label>"
    "<input class='form-control' id='port' type='number' name='port' min='100' max='65000' value='{{socketPort}}'>"
    "</div>"
    "<br><br>"
    "<button type='submit' class='btn btn-primary mb-2'name='save'>Сохранить</button>"
    "</form>";

const char HTTP_HELP[] PROGMEM =
    "<h2>Помощь</h2>"
    "<div id='main' class='col-sm-9'>"
    /*
    "<div id='help_btns'>"
    "<a href='#' class='btn btn-primary'><i class='glyphicon glyphicon-cog'></i>Primary</a>"
    "<a href='#' class='btn btn-secondary'><i class='glyphicon glyphicon-file'></i>Secondary</a>"
    "<a href='#' class='btn btn-success'><i class='glyphicon glyphicon-flag'></i>Success</a>"
    "<a href='#' class='btn btn-danger'><i class='glyphicon glyphicon-lock'></i>Danger</a>"
    "<a href='#' class='btn btn-warning'><i class='glyphicon glyphicon-tags'></i>Warning</a>"
    "</div>"
    */
    "<script src='https://cdn.jsdelivr.net/npm/@webcomponents/webcomponentsjs@2/webcomponents-loader.min.js'></script>"
    "<script type='module' src='https://cdn.jsdelivr.net/gh/zerodevx/zero-md@1/src/zero-md.min.js'></script>"
    "<zero-md src='https://raw.githubusercontent.com/Zud71/ZigStarGW-FW-RU/main/README.md'></zero-md>"
    "</div>";

const char HTTP_ERROR[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<div id='main' class='col-sm-9'>"
    "</div>";

const char HTTP_ETHERNET[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<div id='main' class='col-sm-12'>"
    "<div id='main' class='col-sm-6'><form method='POST' action='saveEther'>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='dhcp' type='checkbox' name='dhcp' {{modeEther}}>"
    "<label class='form-check-label' for='dhcp'>DHCP</label>"
    "</div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='ip'>IP</label>"
    "<input class='form-control' id='ip' type='text' name='ipAddress' value='{{ipEther}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='mask'>Маска</label>"
    "<input class='form-control' id='mask' type='text' name='ipMask' value='{{maskEther}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='gateway'>Шлюз</label>"
    "<input type='text' class='form-control' id='gateway' name='ipGW' value='{{GWEther}}'>"
    "</div>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='disablePingCtrl' type='checkbox' name='disablePingCtrl' {{disablePingCtrl}}>"
    "<label class='form-check-label' for='disablePingCtrl'><b>Отключить</b> проверку шлюза пингом</label>"
    "</div>"
    "</div>"
    "<button type='submit' class='btn btn-primary mb-2'name='save'>Сохранить</button>"
    "</form>";

const char HTTP_GENERAL[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<div id='main' class='col-sm-12'>"
    "<div id='main' class='col-sm-6'><form method='POST' action='saveGeneral'>"
    "<div class='form-group'>"
    "<label for='hostname'>Имя хоста</label>"
    "<input class='form-control' id='hostname' type='text' name='hostname' value='{{hostname}}'>"
    "</div>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='disableWeb' type='checkbox' name='disableWeb' {{disableWeb}}>"
    "<label class='form-check-label' for='disableWeb'>Отключить веб-сервер при подключении сокета</label>"
    "<br>"
    "</div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='refreshLogs'>Обновить журнал консоли</label>"
    "<input class='form-control' id='refreshLogs' type='text' name='refreshLogs' value='{{refreshLogs}}'>"
    "</div>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='webAuth' type='checkbox' name='webAuth' {{webAuth}}>"
    "<label class='form-check-label' for='webAuth'>Включить аутентификацию на веб-сервере</label>"
    "<br>"
    "</div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='webUser'>Имя пользователя</label>"
    "<input class='form-control' id='webUser' type='text' name='webUser' value='{{webUser}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='webPass'>Пароль</label>"
    "<input class='form-control' id='webPass' type='password' name='webPass' value='{{webPass}}'>"
    "</div>"
    "<button type='submit' class='btn btn-primary mb-2' name='save'>Сохранить</button>"
    "</form></div>"
    "</div>";

const char HTTP_ROOT[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<script language='javascript'>checkLatestRelease();</script>"
    "<div id='main' class='col-sm-12'>"
    "<div id='main' class='col-sm-6'>"
    "<div class='card'>"
    "<div class='card-header'>Основные</div>"
    "<div class='card-body'>"
    "<div id='genConfig'>"
    "<strong>Сокет : </strong>{{connectedSocket}}"
    "<br><strong>В работе : </strong>{{uptime}}"
    "<br><strong>ESP температура : </strong>{{deviceTemp}} &deg;C"
    "{{dsTemp}}"
    "<br><strong id='ver' v=" VERSION ">Версия прошивки : </strong>" VERSION 
    #ifdef DEBUG
    " DEBUG"
    #endif
    "<br><strong>Оборудование : </strong>{{hwRev}}"
    "<br><strong>ESP32 модель : </strong>{{espModel}}"
    "<br><strong>Процессор : </strong>{{espCores}} cores @ {{espFreq}} MHz"
    "<br><strong>Флеш-память : </strong>{{espFlashSize}} Mb, {{espFlashType}}"
    "<br><strong>Свободная ОЗУ : </strong>{{espHeapFree}} / {{espHeapSize}} KiB"
    "</div>"
    "</div>"
    "</div><br>"
    "<div class='card'>"
    "<div class='card-header'>Сетевой порт</div>"
    "<div class='card-body'>"
    "<div id='ethConfig'>"
    "{{stateEther}}"
    "</div>"
    "</div>"
    "</div><br>"
    "<div class='card'>"
    "<div class='card-header'>Сеть Wifi</div>"
    "<div class='card-body'>"
    "<div id='wifiConfig'>"
    "{{stateWifi}}"
    "</div>"
    "</div>"
    "</div><br>"
    "<div class='card'>"
    "<div class='card-header'>MQTT</div>"
    "<div class='card-body'>"
    "<div id='mqttConfig'>"
    "{{stateMqtt}}"
    "</div>"
    "</div>"
    "</div><br>"
    "</div>"
    "</div>";

const char HTTP_UPDATE[] PROGMEM =
    "<form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>"
    "<input type='file' name='update' id='file' onchange='sub(this)' style=display:none accept='.bin'>"
    "<label id='file-input' for='file'>   Выбрать файл...</label>"
    "<input type='submit' class='btn btn-danger mb-2' value='Обновить'>"
    "<br><br>"
    "<div id='prg'></div>"
    "<br><div id='prgbar'><div id='bar'></div></div><br></form>"
    "<div id='update_info'>"
    "<h4>Последняя версия на GitHub</h4>"
    "<div id='onlineupdate'>"
    "<h5 id=releasehead></h5>"
    "<div style='clear:both;'>"
    "<br>"
    "</div>"
    "<pre id=releasebody>Получение информации об обновлениях с GitHub...</pre>"
    "<div class='pull-right' style='text-align: center;'>"
    "<a class='pull-right' id='webupdate' href='/web_update'>"
    "<button type='button' class='btn btn-warning'>Онлайн-обновление</button>"
    "</a>"
    "<a style='margin-left: 40px;' class='pull-right' id='downloadupdate'>"
    "<button type='button' class='btn btn-success'>Загрузить</button>"
    "</a>"
    "</div>"
    "</div>"
    "</div>"
    "<div id='update_info'>"
    "<h5>Нажав кнопку «Онлайн-обновление», вы запустите процесс обновления прямо из GitHub.</h5>"
    "<h6>На данный момент ход онлайн-обновления не отображается - нужно дождаться перезагрузки устройства."
    "</h6>"
    "</div>"
    "<div style='clear:both;'>"
    "<br>"
    "</div>"
    "<script language='javascript'>getLatestReleaseInfo();</script>"
    "<script>"
    "function sub(obj){"
    "var fileName = obj.value.split('\\\\');"
    "document.getElementById('file-input').innerHTML = '   '+ fileName[fileName.length-1];"
    "};"
    "$('form').submit(function(e){"
    "e.preventDefault();"
    "var form = $('#upload_form')[0];"
    "var data = new FormData(form);"
    "$.ajax({"
    "url: '/update',"
    "type: 'POST',"
    "data: data,"
    "contentType: false,"
    "processData:false,"
    "xhr: function() {"
    "var xhr = new window.XMLHttpRequest();"
    "xhr.upload.addEventListener('progress', function(evt) {"
    "if (evt.lengthComputable) {"
    "var per = evt.loaded / evt.total;"
    "$('#prg').html('прогресс: ' + Math.round(per*100) + '%');"
    "$('#bar').css('width',Math.round(per*100) + '%');"
    "}"
    "}, false);"
    "return xhr;"
    "},"
    "success:function(d, s) {"
    "console.log('success!');"
    "$('#prg').html('Обновление завершено!<br>Перезагрузка!');"
    "window.location.href='/';"
    "},"
    "error: function (a, b, c) {"
    "}"
    "});"
    "});"
    "</script>";

const char HTTP_MQTT[] PROGMEM =
    "<h2>{{pageName}}</h2>"
    "<div id='main' class='col-sm-12'>"
    "<div id='main' class='col-sm-6'><form method='POST' action='saveMqtt'>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='enb' type='checkbox' name='enable' {{mqttEnable}}>"
    "<label class='form-check-label' for='enb'>Включить</label>"
    "</div>"
    "</div>"
    "<div class='form-group'>"
    "<label for='ip'>Сервер IP</label>"
    "<input class='form-control' id='ip' type='text' name='server' value='{{mqttServer}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='port'>Порт</label>"
    "<input class='form-control' id='port' type='number' name='port' min='100' max='65000' value='{{mqttPort}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='user'>Имя пользователя</label>"
    "<input class='form-control' id='user' type='text' name='user' value='{{mqttUser}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='pass'>Пароль</label>"
    "<input class='form-control' id='pass' type='password' name='pass' value='{{mqttPass}}'>"
    "</div>"
    "<div class='form-group'>"
    "<label for='topic'>Заголовок</label>"
    "<input class='form-control' id='topic' type='text' name='topic' value='{{mqttTopic}}'>"
    "</div>"
    /*"<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='retain' type='checkbox' name='retain' {{mqttRetain}}>"
    "<label class='form-check-label' for='retain'>Retain</label>"
    "</div>"
    "</div>"*/
    "<div class='form-group'>"
    "<label for='port'>Интервал обновления</label>"
    "<input class='form-control' id='interval' type='number' name='interval' min='0' max='3600' value='{{mqttInterval}}'>"
    "</div>"
    "<div class='form-group'>"
    "<div class='form-check'>"
    "<input class='form-check-input' id='discovery' type='checkbox' name='discovery' {{mqttDiscovery}}>"
    "<label class='form-check-label' for='discovery'>Автоматическое обнаружение</label>"
    "</div>"
    "</div>"
    "<button type='submit' class='btn btn-primary mb-2'name='save'>Сохранить</button>"
    "</form>";