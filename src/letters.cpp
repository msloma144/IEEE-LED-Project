#include "lettersLib.h"

using namespace std;

void clear_letters(){
  delete [] A;
  delete [] B;
  delete [] C;
  delete [] D;
  delete [] E;
  delete [] F;
  delete [] H;
  delete [] I;
  delete [] J;
  delete [] K;
  delete [] L;
  delete [] M;
  delete [] N;
  delete [] O;
  delete [] P;
  delete [] Q;
  delete [] R;
  delete [] S;
  delete [] T;
  delete [] U;
  delete [] V;
  delete [] W;
  delete [] X;
  delete [] Y;
  delete [] Z;
  delete [] space_large;
  delete [] space_small;
}


bool* get_sub_array(bool letter[], int letter_len, int row_num) {
    bool *sub_arr = new bool[letter_len]();
    //int i = (row_num - 1) * letter_len;
    int j = 0;
    int i, condition;
    if(row_num > 0){
        i = (row_num) * letter_len;
        condition = (row_num + 1) * letter_len;
    } else{
        i = 0;
        condition = row_num + letter_len;
    }

    for (;i < condition; i++) {
        sub_arr[j] = letter[i];
        j++;
    }
    return sub_arr;
}

bool* getLetterArray(char letter, int row_num) {
        bool *arr;
        int letter_len;
        switch (letter) {
            case 'A':
                arr = A;
                letter_len = A_length;
                break;
            case 'B':
                arr = B;
                letter_len = B_length;
                break;
            case 'C':
                arr = C;
                letter_len = C_length;
                break;
            case 'D':
                arr = D;
                letter_len = D_length;
                break;;
            case 'E':
                arr = E;
                letter_len = E_length;
                break;
            case 'F':
                arr = F;
                letter_len = F_length;
                break;
            case 'G':
                arr = G;
                letter_len = G_length;
                break;
            case 'H':
                arr = H;
                letter_len = H_length;
                break;
            case 'I':
                arr = I;
                letter_len = I_length;
                break;
            case 'J':
                arr = J;
                letter_len = J_length;
                break;;
            case 'K':
                arr = K;
                letter_len = K_length;
                break;
            case 'L':
                arr = L;
                letter_len = L_length;
                break;
            case 'M':
                arr = M;
                letter_len = M_length;
                break;
            case 'N':
                arr = N;
                letter_len = N_length;
                break;
            case 'O':
                arr = O;
                letter_len = O_length;
                break;
            case 'P':
                arr = P;
                letter_len = P_length;
                break;
            case 'Q':
                arr = Q;
                letter_len = Q_length;
                break;
            case 'R':
                arr = R;
                letter_len = R_length;
                break;
            case 'S':
                arr = S;
                letter_len = S_length;
                break;
            case 'T':
                arr = T;
                letter_len = T_length;
                break;
            case 'U':
                arr = U;
                letter_len = U_length;
                break;
            case 'V':
                arr = V;
                letter_len = V_length;
                break;
            case 'W':
                arr = W;
                letter_len = W_length;
                break;
            case 'X':
                arr = X;
                letter_len = X_length;
                break;
            case 'Y':
                arr = Y;
                letter_len = Y_length;
                break;
            case 'Z':
                arr = Z;
                letter_len = Z_length;
                break;
            case '1':
                arr = one;
                letter_len = one_length;
                break;
			      case '2':
                arr = two;
                letter_len = two_length;
                break;
			      case '3':
                arr = three;
                letter_len = three_length;
                break;
			      case '4':
                arr = four;
                letter_len = four_length;
                break;
			      case '5':
                arr = five;
                letter_len = five_length;
                break;
			      case '6':
                arr = six;
                letter_len = six_length;
                break;
			      case '7':
                arr = seven;
                letter_len = seven_length;
                break;
			      case '8':
                arr = eight;
                letter_len = eight_length;
                break;
			      case '9':
                arr = nine;
                letter_len = nine_length;
                break;
            case '0':
                arr = zero;
                letter_len = zero_length;
                break;
    	      case '@':
                arr = at;
                letter_len = at_length;
                break;
    		    case ':':
               arr = colon;
               letter_len = colon_length;
               break;
            case ' ':
               arr = space_large;
               letter_len = space_large_length;
               break;
            default:
                arr = space_small;
                letter_len = space_small_length;
                break;
        }

        return get_sub_array(arr, letter_len, row_num);
}

int getLetterLength(char letter) {
    int letter_len;
    switch (letter) {
        case 'A':
            letter_len = A_length;
            break;
        case 'B':
            letter_len = B_length;
            break;
        case 'C':
            letter_len = C_length;
            break;
        case 'D':
            letter_len = D_length;
            break;;
        case 'E':
            letter_len = E_length;
            break;
        case 'F':
            letter_len = F_length;
            break;
        case 'G':
            letter_len = G_length;
            break;
        case 'H':
            letter_len = H_length;
            break;
        case 'I':
            letter_len = I_length;
            break;
        case 'J':
            letter_len = J_length;
            break;;
        case 'K':
            letter_len = K_length;
            break;
        case 'L':
            letter_len = L_length;
            break;
        case 'M':
            letter_len = M_length;
            break;
        case 'N':
            letter_len = N_length;
            break;
        case 'O':
            letter_len = O_length;
            break;
        case 'P':
            letter_len = P_length;
            break;
        case 'Q':
            letter_len = Q_length;
            break;
        case 'R':
            letter_len = R_length;
            break;
        case 'S':
            letter_len = S_length;
            break;
        case 'T':
            letter_len = T_length;
            break;
        case 'U':
            letter_len = U_length;
            break;
        case 'V':
            letter_len = V_length;
            break;
        case 'W':
            letter_len = W_length;
            break;
        case 'X':
            letter_len = X_length;
            break;
        case 'Y':
            letter_len = Y_length;
            break;
        case 'Z':
            letter_len = Z_length;
            break;
        case ' ':
            letter_len = space_large_length;
            break;
        case '1':
            letter_len = one_length;
            break;
        case '2':
            letter_len = two_length;
            break;
        case '3':
            letter_len = three_length;
            break;
        case '4':
            letter_len = four_length;
            break;
        case '5':
            letter_len = five_length;
            break;
        case '6':
            letter_len = six_length;
            break;
        case '7':
            letter_len = seven_length;
            break;
        case '8':
            letter_len = eight_length;
            break;
        case '9':
            letter_len = nine_length;
            break;
        case '0':
            letter_len = zero_length;
            break;
        case '@':
            letter_len = at_length;
            break;
        case ':':
            letter_len = colon_length;
            break;
        default:
            letter_len = space_small_length;
            break;
    }

    return letter_len;
}
