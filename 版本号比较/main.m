//
//  main.m
//  版本号比较
//
//  Created by nucarf on 2021/3/12.
//

#import <Foundation/Foundation.h>

/**
 * 比较版本号
 *
 * @param v1 第一个版本号
 * @param v2 第二个版本号
 *
 * @return 如果版本号相等，返回 0,
 *         如果第一个版本号低于第二个，返回 -1，否则返回 1.
 */
int compare_version(const char *v1, const char *v2)
{
    assert(v1);
    assert(v2);

    const char *p_v1 = v1;
    const char *p_v2 = v2;

    while (*p_v1 && *p_v2) {
        char buf_v1[32] = { 0 };
        char buf_v2[32] = { 0 };

        char *i_v1 = strchr(p_v1, '.');
        char *i_v2 = strchr(p_v2, '.');
        
        if (!i_v1 || !i_v2) break;

        if (i_v1 != p_v1) {
            strncpy(buf_v1, p_v1, i_v1 - p_v1);
            p_v1 = i_v1;
        } else p_v1++;

        if (i_v2 != p_v2) {
            strncpy(buf_v2, p_v2, i_v2 - p_v2);
            p_v2 = i_v2;
        } else p_v2++;

        int order = atoi(buf_v1) - atoi(buf_v2);
        if (order != 0) return order < 0 ? -1 : 1;
    }

    double res = atof(p_v1) - atof(p_v2);

    if (res < 0) return -1;
    if (res > 0) return 1;
    return 0;
}

int main(int argc, const char *argv[])
{
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        assert(compare_version("2.2.1", "2.1.9") > 0);
        assert(compare_version("2.2.1", "2.2.01") == 0);
        assert(compare_version("2.2.1", "2.2.1") == 0);
        assert(compare_version("2.2", "2.1.1") > 0);
        assert(compare_version("2.2", "2.2.1") < 0);
        assert(compare_version("2.2.3.1", "2.2.3.5") < 0);
        assert(compare_version("2.2.3.1", "2.2.3.0") > 0);
        assert(compare_version("2.2", "2.2.1.4.5") < 0);
        assert(compare_version("2.2.3.4", "2.2.4.4.5") < 0);
        assert(compare_version("2.2.3.4.5.6", "2.2.3.4.5.12") < 0);
        assert(compare_version("2.2.3.4.5.6", "2.2.2.4.5.12") > 0);
        assert(compare_version("3.0.0.1", "3.0.0.0.1") > 0);
        assert(compare_version("3.1", "3.1.") == 0);
    }
    return 0;
}
