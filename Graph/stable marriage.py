# -*- coding: utf-8 -*-
"""
Created on Wed Oct 14 00:02:48 2020

@author: Jovana
"""

#Stable Marriage Problem -  Gale–Shapley algorithm

def stable_matching(n, men_preferences, women_preferences):
    """
    

    Parameters
    ----------
    n : integer 
        Number of people. People are enumerated as 0..n-1
    men_preferences : list of lists
        list of each man's preferences (in descending order).
    women_preferences : list of lists
        list of each woman's preferences (in descending order).

    Returns
    -------
    List containing each man's spouse, where value at i-th index represents the
    woman assigned to that man.

    """

    #List of unmarried men - initially all of them are unmarried.
    unmarried_men = list(range(n))
    
    #List of women's and men's spouses.
    men_spouses = [None] * n
    women_spouses = [None] * n
    
    #Last choice each man made (they don't go up the list once they are rejected)
    men_choices = [0] * n
    
    while unmarried_men:
        
        man = unmarried_men[0]
        his_preferences = men_preferences[man]
        
        woman = his_preferences[men_choices[man]]
        men_choices[man] += 1
        
        her_preferences = women_preferences[woman]
        her_husband = women_spouses[woman]
        
        # if she doesn't have a husband or she prefers this man to her husband, 
        # this man becomes the husband and the old husband (if exists) is rejected.
        if (her_husband == None) or (her_preferences.index(her_husband) > her_preferences[man]):
            women_spouses[woman] = man
            men_spouses[man] = woman
            unmarried_men.pop(0)
            if her_husband != None:
                men_spouses[her_husband] = None
                unmarried_men.append(her_husband)
        
    return men_spouses

prefer_men = [[1, 2, 3, 0], [2, 1, 3, 0], [1, 3, 2, 0], [2, 1, 0, 3]]

prefer_women = [[3, 2, 1, 0], [3, 2, 1, 0], [2, 0, 3, 1], [3, 1, 2, 0]]
  
men_spouses = stable_matching(4, prefer_men, prefer_women)
print(men_spouses)
  


