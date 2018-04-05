SMS Gate
========

[![travic-ci](https://travis-ci.org/sv99/sms_gate.svg?branch=master)](https://travis-ci.org/sv99/sms_gate/builds)
  
Проект создан при прохождении курса от Mail.Ru Group [Углубленное программирование на C/C++](https://stepik.org/course/%D0%A3%D0%B3%D0%BB%D1%83%D0%B1%D0%BB%D0%B5%D0%BD%D0%BD%D0%BE%D0%B5-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D0%BD%D0%B0-CC++-153) на [Stepic.org](https://stepik.org).

Особенности и задачи:

1. Замена для сервисов отправки СМС. Web сервис позволяющий отправить СМС на базе RaspberryPi или аналога.

2. Непосредственно для работы с модемом используем пакет smstools.

3. Web интерфейс позволяющий отправить СМС через REST API с минимальной авторизацией или без нее.

3. Простейшая веб админка для просмотра отправленных и принятых СМС.

Send SMS через USBmodem
-----------------------

Для отправки используем GSM модем и пакет smstools.

[Отправка SMS с 3G/GSM модема](https://habrahabr.ru/post/133085/)
[Управляем сервером посредством СМС](https://habrahabr.ru/post/114912/)

Два варианта получения информации о входящей СМС - проверка каталога и получение события из демона,
можно например организовать пользовательский сигнал.

На debian:
```bash
apt-get install smstools usb-modeswitch minicom
```

Актуальные параметры настройки для модема ZTE MF180
```
#/etc/smsd.conf

[MF180]
device = /dev/ttyUSB1
incoming = yes
baudrate = 115200
# for switching in the modem only mode
#init = at+zcdrun=8
init = at+cpms="me","me",""
# without this circling checking memory with errors
check_memory_method=2
```

Целевая платформа arm. Debian пакет smstool для arm не содержит скрипты sendsms.
Они есть только в версии amd64, были найдены при поиске скрипта sendsms по содержимому всех пакетов.
Эти скрипты не устанавливаются в систему, нужно копировать в ручную.
Пришлось подставлять их в систему отдельно. 

Админка
-------

Планировал прицепить админку на базе Node.js, в рамках курса попробую сделать это дело на С++.

Встраиваемый [HTTP server mongoose](https://github.com/cesanta/mongoose).

UML
---

Вторая диаграмма нарисована в [draw.io](https://www.draw.io/):
![Draw.io Domain Model Diagram](SMSGate_Domain_Model_draw.io.png)

Первая диаграмма нарисована в [StarUML](http://staruml.io/) - **SMSGate_Domain_Model_step1.mdi**:
![StarUML Domain Model Diagram](SMSGate_Domain_Model_step1.jpg)

Дополнительные библиотеки
-------------------------

1. Test framework [google test](https://github.com/google/googletest)

2. Command line parser [boost::program_options](http://www.boost.org/doc/libs/1_61_0/doc/html/program_options.html)

3. Small, safe and fast formatting library [fmt](http://fmtlib.net/latest/index.html)

4. Very fast, header only, C++ logging library [spdlog](https://github.com/gabime/spdlog)

5. Embedded Web Server [mongoose](https://github.com/cesanta/mongoose)

6. Планируется [JSON for Modern C++](https://github.com/nlohmann/json)

Пакетный менеджер hunter
------------------------

[hunter](https://github.com/ruslo/hunter)

```bash
cmake -H. -B_builds -DHUNTER_STATUS_DEBUG=ON -DCMAKE_BUILD_TYPE=Debug
cmake --build _builds
```

sonarqube
---------

Одно из заданий проверка при помощи статического анализатора кода

Установил sonarqube, но для CPP плагин платный, бесплатно проверяют открытые 
проекты расположенные на GitHub.

Нужно авторизоваться на sonarqube.com через github и получить token.
После этого можно проверять проект, результаты появятся в dashboard.

```bash
brew install sonar-runner
```

Кроме sonar-runner нужен build-wrapper от sonarqube.
Загрузить https://sonarqube.com/static/cpp/build-wrapper-macosx-x86.zip,
в настоящий момент возможна только ручная установка.
Теперь можно проверить проект.

Глобальные настройки находятся в файле /usr/local/Cellar/sonar-runner/2.8/libexec/conf/sonar-runner.properties
специфичные для проекта настройки в sonar-project.properties
```
# sonar-project.properties

# SonarQube server for open source projects
sonar.host.url=https://sonarqube.com

# token for github from sonarqube.com dashboard
sonar.login=3155f83fdb2ead3aa6706d3ff532b599987c4576
```

```bash
build-wrapper-macosx-x86 --out-dir bw-outputs cmake --build _builds
sonar-runner
```

https://sonarqube.com/dashboard/index/org.sonarqube:sms-gate-sq-scanner