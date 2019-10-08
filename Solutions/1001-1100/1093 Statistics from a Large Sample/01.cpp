//1093 Statistics from a Large Sample
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int num = 0;
        double min = 0, max = 0, mean = 0, median = 0, mode = 0;
        int lab = 0;
        int sum = 0;
        int freq = 0;
        for (int i = 0; i < 256; i++) {
        	if (count[i] != 0) {
        		if (lab == 0) {
        			lab = 1;
        			min = count[i];
        		} 
        		else {
        			max = count[i];
        		}
        	}
        	if (count[i] > freq) {
        		freq = count[i];
        		mode = i;
        	}
        	num += count[i];
        	sum += count[i] * i;
        	if (i > 0) count[i] += count[i-1];
        } 
        mean = (sum + 0.0) / num;
        if (num % 2 == 0) {
        	int low = num / 2;
        	int high = num / 2 + 1;
        	for (int i = 0; i < 256; i++) {
	        	if (count[i] >= low) {
	        		low = i;
	        	}
	        	if (count[i] >= low) {
	        		high = i;
	        	}  
	        }
	        median = (low + high + 0.0) / 2;
        }
        else {
        	num = num / 2 + 1;
        	for (int i = 0; i < 256; i++) {
	        	if (count[i] >= num) {
	        		median = i;
	        		break;
	        	} 
	        }
        }
        vector<double> res;
        res.push_back(min);
        res.push_back(max);
        res.push_back(mean);
        res.push_back(median);
        res.push_back(mode);
        return res;
    }
};