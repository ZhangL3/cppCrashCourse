#include <cstdio>

struct Element {
  Element* next{};
  Element* previous{};
  void insert_after(Element* new_element) {
    new_element->next = this->next;
    this->next = new_element;
  }
  void insert_before(Element* new_element) {
    new_element->previous = this->previous;
    this->previous = new_element;
  }
  char prefix[2];
  short operating_number;
};

int main() {
  Element trooper1, trooper2, trooper3, trooper00, trooper01, trooper02;
  trooper1.prefix[0] = 'T';
  trooper1.prefix[1] = 'K';
  trooper1.operating_number = 10;
  trooper2.prefix[0] = 'F';
  trooper2.prefix[1] = 'N';
  trooper2.operating_number = 11;
  trooper3.prefix[0] = 'L';
  trooper3.prefix[1] = 'S';
  trooper3.operating_number = 12;

  trooper1.insert_after(&trooper2);
  trooper2.insert_after(&trooper3);
  trooper3.insert_before(&trooper2);
  trooper2.insert_before(&trooper1);

  for(Element* cursor = &trooper1; cursor; cursor = cursor->next) {
    printf("Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    // printf("next->prefix operating_number: %c%c %d\n", cursor->next->prefix[0], cursor->next->prefix[1], cursor->next->operating_number);
  }

  printf("------------------------------\n");

  for(Element* cursor = &trooper3; cursor; cursor = cursor->previous) {
    printf("Storm Trooper %c%c-%d\n", cursor->prefix[0], cursor->prefix[1], cursor->operating_number);
    // printf("next->prefix operating_number: %c%c %d\n", cursor->previous->prefix[0], cursor->previous->prefix[1], cursor->previous->operating_number);
  }
}