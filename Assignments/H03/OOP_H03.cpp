
// Author:           Byron Dowling
// Email:            byrondowling7@gmail.com
// Label:            H03
// Title:            Bubble Sort Correction
// Course:           2143
// Semester:         Fall 2020


// It would be better to use the built in 
// vector "sort". But ... oh well.
void Hand::Sort() {

    // Index "i" 
    for (int i = 0; i < Size(); i++) {
        // Index "j"
        for (int j = i; j < Size(); j++) {
            //Comparing cards at position i and j 
            if (Cards[i]->rank > Cards[j]->rank) {
                cout << "swapping" << endl;

                // standard swap 
                Card* temp = Cards[i];
                Cards[i] = Cards[j];
                Cards[j] = temp;
            }
        }
    }
}
