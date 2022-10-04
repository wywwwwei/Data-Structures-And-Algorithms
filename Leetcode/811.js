/**
 * 811. 子域名访问计数
 * link：https://leetcode.cn/problems/subdomain-visit-count/
 */

/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function (cpdomains) {
    const domains = new Map();
    for (const cpdomain of cpdomains) {
        const [times, domain] = cpdomain.split(" ");
        const domainArr = domain.split(".");
        const n = domainArr.length;
        for (let i = 0; i < n; i++) {
            const subdomain = domainArr.slice(i).join('.');
            domains.set(subdomain, +times + (domains.has(subdomain) ? domains.get(subdomain) : 0));
        }
    }
    return Array.from(domains).map((element) => {
        const [domain, times] = element;
        return times.toString() + " " + domain;
    });
};