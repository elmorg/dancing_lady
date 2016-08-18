#ifndef __YOTTA_BUILD_INFO_H__
#define __YOTTA_BUILD_INFO_H__
// yotta build info, #include YOTTA_BUILD_INFO_HEADER to access
#define YOTTA_BUILD_YEAR 2016 // UTC year
#define YOTTA_BUILD_MONTH 8 // UTC month 1-12
#define YOTTA_BUILD_DAY 18 // UTC day 1-31
#define YOTTA_BUILD_HOUR 18 // UTC hour 0-24
#define YOTTA_BUILD_MINUTE 34 // UTC minute 0-59
#define YOTTA_BUILD_SECOND 51 // UTC second 0-61
#define YOTTA_BUILD_UUID 36020763-71e1-4862-8e52-82f621f65641 // unique random UUID for each build
#define YOTTA_BUILD_VCS_ID db3e9d4cb1790bbbf65a4c44d3e5a250ab1adc22 // git or mercurial hash
#define YOTTA_BUILD_VCS_CLEAN 0 // evaluates true if the version control system was clean, otherwise false
#define YOTTA_BUILD_VCS_DESCRIPTION db3e9d4 // git describe or mercurial equivalent
#endif // ndef __YOTTA_BUILD_INFO_H__
