class CalculatorConundrum {
    public String calculate(int operand1, int operand2, String operation) throws IllegalOperationException, ArithmeticException, IllegalArgumentException
    {
        
        if (operation == null)
        {
            throw new IllegalArgumentException("Operation cannot be null");
        }
        else if (operation.equals(""))
        {
            throw new IllegalArgumentException("Operation cannot be empty");
        }
        else if (!(operation.equals("+") || operation.equals("*") || operation.equals("/")))
        {
            throw new IllegalOperationException("Operation '" + operation + "' does not exist");
        }
        
            String calculation = operand1 + " " + operation + " " + operand2 + " = " ;
            int result = 0;

        try
        {
            switch(operation)
                {
                    case "+":
                        result = operand1 + operand2;
                        break;
                    case "*":
                        result = operand1 * operand2;
                        break;
                    case "/":
                        result = operand1 / operand2;
                        break;
                }
            calculation += result;
        }
        catch(ArithmeticException e)
        {
            throw new IllegalOperationException("Division by zero is not allowed", e);
        }
        return calculation;
    }
}
