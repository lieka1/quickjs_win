# quick js for visual studio & windows
quick js for visual studio this project should work both binary and lib but not fully tested <br/>

about quickjs https://bellard.org/quickjs/

## install
- compile pthread in SDK folder
- add pthread.dll to working folder or debug folder
- compile the quickjs

## changes
- add pthread-win32 to support 
- add some atom operation (not sure about visual c suport with atom opeation)

## known issue
- [ ] Due to ftw is not working for windows and visual studio so enumerate_tests can't work
- [ ] some of attom operation may not work
- [ ] only tested on windows 10