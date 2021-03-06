#ifndef __BK_FILE_SYSTEM_H__
#define __BK_FILE_SYSTEM_H__

// Standard headers.
#include <stdio.h>

// blackhart headers.
#include "foundation\BkExport.h"
#include "foundation\BkAtomicDataType.h"

typedef FILE	BkFlux;

// ~~~~~ Dcl(PUBLIC) ~~~~~

/*! \brief Checks if a file exists.
 *
 * \param filename The file to check.
 * \return True if the file exists, false otherwise.
 */
extern BK_API bool	BkFileSystem_FluxExists(char const* filename);

/*! \brief Opens a flux.
 *
 * \param flux A pointer to the flux.
 * \param filename The file to open.
 * \param mode The file access mode.
 */
extern BK_API void	BkFileSystem_OpenFlux(BkFlux** flux, char const* __restrict filename, char const* __restrict mode);

/*! \brief Closes a flux.
 *
 * \param flux A pointer to the flux to close.
 */
extern BK_API void	BkFileSystem_CloseFlux(BkFlux** flux);

/*! \brief Writes a message into a flux.
 *
 * \param flux A pointer to the opened flux.
 * \param str The message to write.
 */
extern BK_API void	BkFileSystem_WriteToFlux(BkFlux* flux, char const* str);

/*! \brief Reads from a file.
 *
 * \param path The file to read.
 * \param buffer The buffer will contains the data [OUT]. Allocate and populate by the function.
 * \param buffer_size The size of the buffer. Populate by the function.
 */
extern BK_API void	BkFileSystem_ReadFromPath(char const* path, char** buffer, size_t* buffer_size);

/*! \brief Reads from a flux.
 *
 * \param flux The flux to read. The flux must be open!
 * \param buffer The buffer will contains the data [OUT]. Allocate and populate by the function.
 * \param buffer_size The size of the buffer. Populate by the function.
 */
extern BK_API void	BkFileSystem_ReadFromFlux(BkFlux* flux, char** buffer, size_t* buffer_size);

/*! \brief Combines two paths.
 *
 * \param dst The buffer that will contains the combined path. Must be allocated before calling this function.
 * \param str1 The first path.
 * \param str2 The second path.
 */
extern BK_API void	BkFileSystem_CombinePath(char* __restrict dst, char const* __restrict str1, char const* __restrict str2);

#endif