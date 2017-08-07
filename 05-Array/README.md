# Dutch Flag partition
Keep in mind
         
         small_set(< pivot): [0, small];
         middle_set(= pivot): [small+1, middle];
         larger_set(> pivot): [middle+1, large-1];
         untouched_set : [large, A.size()-1]
         
         init: small = -1, middle = -1, large = 0
 
