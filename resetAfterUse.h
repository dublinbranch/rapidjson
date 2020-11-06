#pragma once

/**
 *small helper class used to set and reset to initial value call like
 *ResetAfterUse r{rapidAssertEnabled, false};
 */
template <typename K>
class ResetAfterUse {
      public:
	ResetAfterUse() = default;
	void set(K& key, const K& value) {
		old       = key;
		key       = value;
		this->key = &key;
	}
	ResetAfterUse(K& key, const K& value) {
		set(key, value);
	}
	~ResetAfterUse() {
		*key = old;
	}

      private:
	K* key = nullptr;
	K  old;
};

