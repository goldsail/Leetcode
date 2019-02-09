class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        
        // define ratio[i] = wage[i] / quality[i]
        // iterate in order of ratio
        // maintain a heap to get K smallest qualities
        
        // initialize a vector of all workers
        int N = quality.size();
        this->workers = vector<pair<double, double>>(N);
        for (int i = 0; i < N; i++) {
            workers[i] = pair<double, double>(quality[i], wage[i]);
        }
        
        // sort these workers in order of ratio, from smallest to greatest
        sort(workers.begin(), workers.end(), [this](pair<double, double> a, pair<double, double> b) {
            double ra = a.second / a.first;
            double rb = b.second / b.first;
            return ra < rb;
        });
        
        // create a heap that contains the indices of K workers with smallest quality
        auto comp = [this](int a, int b) {
            return this->workers[a].first < this->workers[b].first;
        };
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        
        // maintain sum of the qualities in the heap
        double sum = 0;
        double ret = LONG_MAX;
        
        for (int i = 0; i < N; i++) {
            heap.push(i);
            sum += workers[i].first;
            while (heap.size() > K) {
                sum -= workers[heap.top()].first;
                heap.pop();
            }
            if (heap.size() == K) {
                double cost = sum * workers[i].second / workers[i].first;
                ret = min(ret, cost);
            }
        }
        return ret;
    }
    
private:
    vector<pair<double, double>> workers;
};