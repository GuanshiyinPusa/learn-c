// Suppose you have this structure:
struct gas {
	float distance;
	float gals;
	float mpg;
};

// a. Devise a function that takes a struct gas argument. Assume that the passed
// structure contains the distance and gals information. Have the function
// calculate the correct value for the mpg member and return the now completed
// structure.
struct gas calculate_mpg(struct gas gs_sample) {
	gs_sample.mpg = gs_sample.distance / gs_sample.gals;
	return gs_sample;
}

// b. Devise a function that takes the address of a struct gas argument. Assume
// that the passed structure contains the distance and gals information. Have
// the function calculate the correct value for the mpg member and assign it to
// the appropriate member.
void calculate_mpg_ptr(struct gas *gas_sample_ptr) {
	gas_sample_ptr->mpg = gas_sample_ptr->distance / gas_sample_ptr->gals;
}

// Correct:
struct gas mpgs(struct gas trip) {
	if (trip.gals > 0)
		trip.mpg = trip.distance / trip.gals;
	else
		trip.mpg = -1.0;
	return trip;
}

void set_mpgs(struct gas *ptrip) {
	if (ptrip->gals > 0)
		ptrip->mpg = ptrip->distance / ptrip->gals;
	else
		ptrip->mpg = -1.0;
}
