#include <stdio.h>

struct entry {
  char word[15];
  char definition[100];
};

int comp_words(const char w1[], const char w2[]);
int dict_sort(struct entry dict[], int dict_size);

int main(void) {
  struct entry dictionary[26] = {{"nebula", "a cloud of gas in space"},
                                 {"quartz", "a hard mineral crystal"},
                                 {"xenon", "a colorless gas element"},
                                 {"breeze", "a light wind"},
                                 {"yonder", "at some distance"},
                                 {"glyph", "a carved symbol"},
                                 {"orbit", "path around a body"},
                                 {"delta", "river mouth landform"},
                                 {"kettle", "a pot for boiling water"},
                                 {"violet", "a purple flower"},
                                 {"anchor", "a device to hold ships"},
                                 {"ember", "a glowing coal"},
                                 {"jungle", "a dense tropical forest"},
                                 {"whisk", "to beat or stir quickly"},
                                 {"tunnel", "an underground passage"},
                                 {"cactus", "a spiny desert plant"},
                                 {"harbor", "a sheltered port"},
                                 {"lumen", "a unit of light"},
                                 {"zebra", "a striped animal"},
                                 {"paddle", "to move through water"},
                                 {"forest", "a large area of trees"},
                                 {"island", "land surrounded by water"},
                                 {"rocket", "a vehicle for space travel"},
                                 {"saddle", "a seat for riding animals"},
                                 {"utensil", "a tool for cooking"},
                                 {"echo", "a reflected sound"}};

  dict_sort(dictionary, 26);

  for (int i = 0; i < 26; i++) {
    printf("%s | %s\n", dictionary[i].word, dictionary[i].definition);
  }

  return 0;
}

int comp_words(const char w1[], const char w2[]) {
  int index = 0;

  while (w1[index] != '\0') {
    if (w1[index] < w2[index])
      return -1;
    else if (w1[index] > w2[index])
      return 1;

    index++;
  }

  if (w1[index] == '\0')
    return 0;
}

int dict_sort(struct entry dict[], int dict_size) {
  int j, k, comp;
  struct entry temp;

  for (j = 0; j < dict_size - 1; j++) {
    for (k = j + 1; k < dict_size; k++) {
      comp = comp_words(dict[j].word, dict[k].word);

      if (comp == 1) {
        temp = dict[j];
        dict[j] = dict[k];
        dict[k] = temp;
      }
    }
  }
}
