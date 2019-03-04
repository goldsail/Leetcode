class Solution {
public:
    int evaluate(string expression) {
        this->variables = unordered_map<string, stack<int>>();
        this->pos = 0;
        this->expr = expression;
        return evaluate();
    }
    
private:
    // There are two challenges:
    // 
    // 1. Each variable in the "let" expression has its concept of scope. 
    // From the recursive descent approach, we parse the expression token by token **recursively**,
    // which suggests that we put all variables in a hash table of **stacks**.
    // Hence, modification to a variable outside the scope will be exposed until we reach the end of the scope, 
    // when we can pop the variable from the stack and expose its previous value outside the scope.
    //
    // 2. It is not an LL(0) parser because we cannot determine how many variable-expression pairs in a "let" expression 
    // until we peek the next two tokens. There are three cases, each of them leading to a different situation:
    //     a) `(let v1 e1 v2)`: 'v2' is actually an expression rather than a variable name
    //     b) `(let v1 e1 (...))`: '(...)' is an expression at the end of the "let" expression
    //     c) `(let v1 e1 v2 x)` where 'x' is a character other than ')': 'x' is an expression
    // Therefore, we have two versions of tokenizers:
    //     advance_token() reads one token and sets the current position forward
    //     peek_two_tokens() reads the next two tokens but keeps the current position still 
    
    
    unordered_map<string, stack<int>> variables; // stores variables in the stack
    size_t pos; // current position of the tokenizer
    string expr; // copy of the target expression to parse
    
    int evaluate() {
        
        string curr = advance_token();
        
        if (curr == "(") { // beginning of an expression
            
            string curr = advance_token(); // first token in the expression
            
            if (curr == "add") {
                int e1 = evaluate();
                int e2 = evaluate();
                assert_(advance_token() == ")", "brackets do not match");
                return e1 + e2;
            }
            
            if (curr == "mult") {
                int e1 = evaluate();
                int e2 = evaluate();
                assert_(advance_token() == ")", "brackets do not match");
                return e1 * e2;
            }
            
            if (curr == "let") {
                // local variables pushed in this scope; should be popped at the end of this scope
                unordered_set<string> local_variables;
                
                bool exit_flag = false;
                do { // handle the variable-expression pairs
                    string var_name = advance_token();
                    int expr_val = evaluate();
                    if (variables.find(var_name) == variables.end()) {
                        variables[var_name] = stack<int>();
                    }
                    if (local_variables.find(var_name) == local_variables.end()) {
                        variables[var_name].push(expr_val);
                        local_variables.insert(var_name);
                    } else {
                        variables[var_name].pop();
                        variables[var_name].push(expr_val);
                    }
                    
                    // peek the next two tokens to see if this is the end of the n variable-expression pairs
                    exit_flag = false;
                    
                    pair<string, string> next_two_tokens = peek_two_tokens();
                    string next_token_1 = next_two_tokens.first;
                    string next_token_2 = next_two_tokens.second;
                    if (next_token_1[0] >= 'a' && next_token_1[0] <= 'z') {
                        if (next_token_2 == ")") {
                            exit_flag = true; // followed by a variable and a right bracket: exit the loop
                        } else {
                            exit_flag = false; // followed by more variable-expression pairs: do not exit the loop
                        }
                    } else {
                        exit_flag = true; // followed by an expression: exit the loop
                    }
                } while (!exit_flag);
                //
                int expr_val = evaluate();
                for (string val_name : local_variables) {
                    variables[val_name].pop();
                }
                assert_(advance_token() == ")", "brackets do not match");
                return expr_val;
            }
                
            assert_(false, "syntax error: invalid expression name");
            return 0;
            
        } else if (curr[0] >= 'a' && curr[0] <= 'z') { // the token is a variable name
            assert_(variables.find(curr) != variables.end() && variables[curr].size() > 0, "variable not defined");
            return variables[curr].top(); // loop up the variable and return its value
        } else { // the token is an integer
            stringstream ss;
            ss << curr;
            int val;
            ss >> val;
            return val; // return its value
        }
        
    }
    
    string advance_token() {
        
        while (pos < expr.size() && expr[pos] == ' ') {
            pos++; // skip white characters
        }
        if (pos >= expr.size()) {
            assert_(false, "reaches end of file");
        }
        
        if (expr[pos] == '(') {
            pos++;
            return "("; // the token is a left bracket
        } else if (expr[pos] == ')') {
            pos++;
            return ")"; // the token is a right bracket
        } else {
            stringstream ss;
            do {
                ss << expr[pos];
                pos++;
            } while (pos < expr.size() && expr[pos] != ' ' && expr[pos] != ')');
            return ss.str(); // the token is a word beginning with a letter or a digit or a negation sign
        }
    }
    
    pair<string, string> peek_two_tokens() {
        size_t prev_pos = this->pos;
        string token_1 = advance_token();
        string token_2 = advance_token();
        this->pos = prev_pos;
        return pair<string, string>(token_1, token_2);
    }
    
    static void assert_(bool condition, const char *message) {
        if (!condition) {
            cout << message << endl;
            throw message;
        }
    }
};
