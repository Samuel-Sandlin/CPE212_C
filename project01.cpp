
void GetNextImage(ifstream& datastream, int counters[], Record& data)
{
		// Read the first digit on the line.
	datastream >> data.digit;

		// Increment the number of times that digit has been encountered
	counters[data.digit]++;
		
		// Ignore the commas between digits
	datastream.ignore(1);

		// Fill the image array
	for( int i = 0; i < MAXROWS; i++ )
	{
		for( int j = 0; j < MAXCOLS; j++ )
		{
			datastream >> data.image[i][j];
			datastream.ignore(1);
		}
	}

}



void Transpose(int image[MAXROWS][MAXCOLS])
{
		// temporary matrix to swap rows and columns
	int temp[MAXROWS][MAXCOLS];
	
		// Copy the matrix to the temporary matrix
	for( int i = 0; i < MAXROWS; i++ )
	{
		for( int j = 0; j < MAXCOLS; j++ )
		{
			temp[i][j] = image[i][j];
		}
	}

		// swap each row and column from the original matrix: [j][i]
	for( int i = 0; i < MAXROWS; i++ )
	{
		for( int j = 0; j < MAXCOLS; j++ )
		{
			image[j][i] = temp[i][j];


		// Previous Code ( DID NOT WORK )

	/*
				// Store the location in the array to a temporary variable
			temp = image[i][j];

				// Swap the rows and columns and store that value in 
				// the *original* location
			image[i][j] = image[j][i];

				// store the orignal location to the "swapped" location
			image[j][i] = temp;
	*/


		}
	}
}



void FlipHorizontal(int image[MAXROWS][MAXCOLS])
{
		// int variable used as a placeholder so data is not lost
		// when swapping locations in the matrix
	int temp;

	for( int i = 0; i < (MAXROWS); i++ )
	{
		for( int j = 0; j < (MAXCOLS/2); j++ )
		{
				// Store the location in the array to a temporary variable
			temp = image[i][j];

				// Swap the orignal location with the location horizontally opposite
			image[i][j] = image[i][MAXCOLS-j-1];
			image[i][MAXCOLS-j-1] = temp;
		}
	}
}



void FlipVertical(int image[MAXROWS][MAXCOLS])
{
		// int variable used as a placeholder so data is not lost
		// when swapping locations in the matrix
	int temp;

	for( int i = 0; i < (MAXROWS/2); i++ )
	{
		for( int j = 0; j < (MAXCOLS); j++ )
		{
				// Store the location in the array to a temporary variable
			temp = image[i][j];

				// Swap the orignal location with the location vertically opposite
			image[i][j] = image[MAXROWS-i-1][j];
			image[MAXROWS-i-1][j] = temp;
		}
	}
}



void RotateCW(int image[MAXROWS][MAXCOLS])
{
	Transpose(image);
	FlipHorizontal(image);
}




void RotateCCW(int image[MAXROWS][MAXCOLS])
{
	Transpose(image);
	FlipVertical(image);
}
