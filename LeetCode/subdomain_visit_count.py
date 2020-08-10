class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        result = []
        d = {}
        for domain in cpdomains:
            value, domain = domain.split(" ")
            subDomain = domain
            subDomainCount = domain.count(".")
            while subDomainCount >= 0:
                if d.get(".".join(subDomain.split(".")[domain.count(".") - subDomainCount:])) == None:
                    d.update({".".join(subDomain.split(".")[domain.count(".") - subDomainCount:]): value})
                else:
                    d.update({".".join(subDomain.split(".")[domain.count(".") - subDomainCount:]): int(
                        d.get(".".join(subDomain.split(".")[domain.count(".") - subDomainCount:]))) + int(value)})
                subDomainCount = subDomainCount - 1;

        for key in d.keys():
            result.append("" + str(d.get(key)) + " " + key)
        return result
