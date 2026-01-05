namespace hellmath {

// TODO: Task 1 - Define an `AccountStatus` enumeration to represent the four
// account types: `troll`, `guest`, `user`, and `mod`.
    enum class AccountStatus{
        troll, guest, user, mod
    };

// TODO: Task 1 - Define an `Action` enumeration to represent the three
// permission types: `read`, `write`, and `remove`.
    enum class Action{
        read, write, remove
    };

// TODO: Task 2 - Implement the `display_post` function, that gets two arguments
// of `AccountStatus` and returns a `bool`. The first argument is the status of
// the poster, the second one is the status of the viewer.
    bool display_post(AccountStatus poster, AccountStatus viewer){
        if(poster == AccountStatus::troll && viewer != AccountStatus::troll){
            return false;
        }
        else if (poster != AccountStatus::troll){
            return true;
        }
        else{
            return true;
        }
    }

// TODO: Task 3 - Implement the `permission_check` function, that takes an
// `Action` as a first argument and an `AccountStatus` to check against. It
// should return a `bool`.
    bool permission_check(Action a, AccountStatus account){
        switch(account){
            case AccountStatus::guest:
                if(a == Action::read){
                    return true;
                }
                else{
                    return false;
                }
                break;
            case AccountStatus::user:
            case AccountStatus::troll:
                if(a == Action::read || a == Action::write){
                    return true;
                }
                else{
                    return false;
                }
                break;
            default:
                return true;
                break;
        }
    }

// TODO: Task 4 - Implement the `valid_player_combination` function that
// checks if two players can join the same game. The function has two parameters
// of type `AccountStatus` and returns a `bool`.
    bool valid_player_combination(AccountStatus player1, AccountStatus player2){
        if(player1 == AccountStatus::guest || player2 == AccountStatus::guest){
            return false;
        }
        else if (player1 == AccountStatus::troll && player2 == AccountStatus::troll){
            return true;
        }
        else if ((player1 == AccountStatus::troll && player2 != AccountStatus::troll) || (player1 != AccountStatus::troll && player2 == AccountStatus::troll)){
            return false;
        }
        else{
            return true;
        }
    }

// TODO: Task 5 - Implement the `has_priority` function that takes two
// `AccountStatus` arguments and returns `true`, if and only if the first
// account has a strictly higher priority than the second.
    bool has_priority(AccountStatus first, AccountStatus second){
        if(first == AccountStatus::mod && second != AccountStatus::mod){
            return true;
        }
        else if(first == AccountStatus::user && (second != AccountStatus::mod && second != AccountStatus::user)){
            return true;
        }
        else if (first == AccountStatus::guest && second == AccountStatus::troll){
            return true;
        }
        else{
            return false;
        }
    }

}  // namespace hellmath
