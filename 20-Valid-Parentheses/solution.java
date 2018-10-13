class Solution {
    public boolean isValid(String s) {
        Stack<String> stringStack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            switch (ch) {
                case '[':
                case '(':
                case '{':
                    stringStack.push(String.valueOf(ch));
                    break;
                case ']':
                    if (stringStack.empty()) {
                        return false;
                    }
                    char t = stringStack.pop().charAt(0);
                    if (t == '[') {
                        continue;
                    }else {
                        return false;
                    }
                case ')':
                    if (stringStack.empty()) {
                        return false;
                    }
                    char q = stringStack.pop().charAt(0);
                    if (q == '(') {
                        continue;
                    }else {
                        return false;
                    }
                case '}':
                    if (stringStack.empty()) {
                        return false;
                    }
                    char w = stringStack.pop().charAt(0);
                    if (w == '{') {
                        continue;
                    }else {
                        return false;
                    }
                default:
                    break;
            }
        }
        return stringStack.empty();        
    }
}