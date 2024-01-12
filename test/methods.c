
struct foo {
	int age;
};

int foo.get_age(this) {
	return this.age;
}

int foo.set_age(*this, int new_age)
{
	return this->age = new_age;
}

int main()
{
	struct foo f = {25};
	struct foo *ptr = &f;

	f.get_age();
	ptr->get_age();
	f.set_age(30);
	ptr->set_age(35);
	return 0;
}
