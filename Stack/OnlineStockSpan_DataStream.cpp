/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price in one day is the maximum number of consecutive days (starting from that day and going backward) for 
which the stock price was less than or equal to the price of that day.

  */


int next(int price) {
       int span=1;
       
       while(!s.empty() && s.top().first<=price){
           span+=s.top().second;
           s.pop();
       }
       s.push({price,span});
       return span;
    }
