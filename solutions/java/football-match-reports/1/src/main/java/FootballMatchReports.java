public class FootballMatchReports {    
    public static String onField(int shirtNum) {
        
        String msg = "";
        switch(shirtNum){
            case 1:
                msg = "goalie";
                break;
            case 2:
                msg = "left back";
                break;
            case 3:
                msg = "center back";
                break;
            case 4:
                msg = "center back";
                break;
            case 5:
                msg = "right back";
                break;
            case 6:
                msg = "midfielder";
                break;
            case 7:
                msg = "midfielder";
                break;
            case 8:
                msg = "midfielder";
                break;
            case 9:
                msg = "left wing";
                break;
            case 10:
                msg = "striker";
                break;
            case 11:
                msg = "right wing";
                break;
            default:
                msg = "invalid";
                break;
        }
        return msg;
    }
}
