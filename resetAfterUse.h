#pragma once

/**
 *small helper class used to set and reset to initial value call like
 *ResetAfterUse r{rapidAssertEnabled, false};
 */
template <typename K>
class ResetAfterUse {
      public:
    ResetAfterUse(K& key, const K& value) {
        old       = key;
        key       = value;
        this->key = &key;
    }
    ~ResetAfterUse() {
        *key = old;
    }

      private:
    K* key;
    K  old;
};
