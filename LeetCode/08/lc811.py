# LeetCode 811. Subdomain Visit Count `E`
# 1sk | 99% | 36'
# A~0h15

class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        dic = {}
        for dom in cpdomains:
            cnt, dom = dom.split()
            cnt = int(cnt)
            subdoms = dom.split(".")
            for i in range(len(subdoms)):
                key = ".".join(subdoms[i:])
                if key in dic:
                    dic[key] += cnt
                else:
                    dic[key] = cnt

        return [str(cnt) + " " + dom for dom, cnt in dic.items()]
