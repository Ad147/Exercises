// LeetCode929-UniqueEmailAddresses.cs
// Ad147
// Init: 19Jan15

/* -----------------------------------------------------------------------------

929. Unique Email Addresses

Easy

Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  
For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  
(Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.  
This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  
(Again, this rule does not apply for domain names.)

It is possible to use both of these rules at the same time.

Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

Example 1:

```
Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
Output: 2
Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails
```

Note:

- 1 <= emails[i].length <= 100
- 1 <= emails.length <= 100
- Each emails[i] contains exactly one '@' character.

----------------------------------------------------------------------------- */

// solution ====================================================================

// Runtime: 128 ms, faster than 98.06% of C# online submissions for Unique Email Addresses.

public class Solution
{
    public int NumUniqueEmails(string[] emails)
    {
        var set = new HashSet<string>();

        foreach (var email in emails)
        {
            var str = new StringBuilder();

            for (int i = 0; i < email.Length; i++)
            {
                char ch = email[i];
                if (ch == '.') { continue; }
                else if (ch == '+' || ch == '@')
                {
                    while (ch != '@') { ch = email[++i]; }

                    while (i < email.Length) { str.Append(email[i++]); }
                }
                else { str.Append(ch); }
            }

            set.Add(str.ToString());
        }

        return set.Count;
    }
}

// solution ====================================================================

// Runtime: 136 ms, faster than 83.50% of C# online submissions for Unique Email Addresses.

public class Solution
{
    public int NumUniqueEmails(string[] emails)
    {
        var unique_emails = new System.Collections.Generic.HashSet<string>();

        foreach (var email in emails)
        {
            string[] split_names = email.Split('@');
            string local_name = split_names[0];
            string domain_name = split_names[1];
            local_name = local_name.Split('+')[0];
            local_name = local_name.Replace(".", string.Empty);

            unique_emails.Add(local_name + domain_name);
        }

        return unique_emails.Count;
    }
}
