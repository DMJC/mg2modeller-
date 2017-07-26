#ifndef DIVIDER_H
#define DIVIDER_H

class divider{
	public:

	static int divideri(int var1, int var2)
	{
        int answer = 0;
        if (var2 == 0 || var2 == -0){
                answer = 0;
        	return answer;
        }
        	answer = (var1 / var2);
        	return answer;
	}

	static double dividerd(double var1, double var2)
	{
	double answer = 0.0;
	if (var2 == 0.0 || var2 == -0.0){
	        answer = 0.0;
	        return answer;
	}
	        answer = var1 / var2;
	        return answer;
	}
};

#endif
