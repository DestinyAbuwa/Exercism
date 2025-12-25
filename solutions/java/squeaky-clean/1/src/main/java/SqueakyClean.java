class SqueakyClean {
    static String clean(String identifier) {
        StringBuilder builder = new StringBuilder();

        char[] charArray = identifier.toCharArray();
        boolean upper = false;
        
        for(char a: charArray){
            
            if (upper == true){
                builder.append(Character.toUpperCase(a));
                upper = false;
            }
            else if(Character.isWhitespace(a)){
                builder.append('_');
            }
            else if (a == '-'){
                upper = true;
                continue;
            }
            else if (a == '4' || a == '3' || a == '0' ||a == '1' || a == '7'){
                switch(a){
                    case '4':
                        builder.append('a');
                        break;
                    case '3':
                        builder.append('e');
                        break;
                    case '0':
                        builder.append('o');
                        break;
                    case '1':
                        builder.append('l');
                        break;
                    case '7':
                        builder.append('t');
                        break;
                }
            }
            else if (!Character.isLetter(a))
            {
                continue;
            }
            else{
                builder.append(a);
            }
        }

        return builder.toString();
    }
}
