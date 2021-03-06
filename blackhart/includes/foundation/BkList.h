#ifndef __BK_LIST_H__
#define __BK_LIST_H__

// blackhart headers.
#include "foundation\BkExport.h"
#include "foundation\BkAtomicDataType.h"

/*! \brief Checks if the BkList has no elements
*
* \param list Any BkList element
* \return TRUE if the BkList is empty, FALSE otherwise
*/
#define BkList_Empty(list)	(BK_ISNULL(list))

/*! \brief Gets the element's data in a BkList
*
* \param list Any BkList element
* \return The element's data, or NULL if there are no element's data
*/
#define BkList_Data(list)	(list->data)

/*! \brief Gets the previous element in a BkList
*
* \param list Any BkList element
* \return The previous element, or NULL if there are no previous elements
*/
#define BkList_Previous(list)	(list->previous)

/*! \brief Gets the next element in a BkList
*
* \param list Any BkList element
* \return The next element, or NULL if there are no next elements
*/
#define BkList_Next(list)	(list->next)

struct BkList
{
	void*	data;
	struct BkList*	next;
	struct BkList*	previous;
};

// ~~~~~ Dcl(PUBLIC) ~~~~~

/*! \brief Gets the first element in a BkList
 *
 * \param obj Any BkList element
 * \return The first element in the BkList, or NULL if the BkList has no elements
 */
extern BK_API struct BkList*	BkList_Front(struct BkList* obj);

/*! \brief Gets the last element in a BkList
*
* \param obj Any BkList element
* \return The last element in the BkList, or NULL if the BkList has no elements
*/
extern BK_API struct BkList*	BkList_Back(struct BkList* obj);

/*! \brief Gets the number of elements in a BkList
*
* \param obj Any BkList element
* \return The number of elements in the BkList
*/
extern BK_API uint32	BkList_Size(struct BkList* obj);

/*! \brief Frees all of the memory used by a BkList
* If list elements contain dynamically-allocated memory, you should either use BkList_ClearFull() or free them manually first
* \param obj Any BkLIst element
*/
extern BK_API void	BkList_Clear(struct BkList* obj);

/*! \brief Gets the element at a given position in a BkList
*
* \param obj Any BkList element
* \param index The position of the element
* \return The element, or NULL if the position is of the end of the BkList
*/
extern BK_API struct BkList*	BkList_Get(struct BkList* obj, uint32 const index);

/*! \brief Inserts a new element into the list at the given position
*
* \param obj Any BkList element
* \param data The data for the new element
* \param index The position to insert the element. If obj is larger than the number of elements in the list, the new element is added on to the end of the list
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_Insert(struct BkList* obj, void* data, uint32 const index);

/*! \brief Remove an element from a BkList
* If two elements contain the same pData, only the fist is removed. If none of the elements contain the pData, the BkList is unchanged
* \param obj Any BkList element
* \param data The data of the element to remove
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_Erase(struct BkList* obj, void* data);

/*! \brief Remove an element from a BkList
* If two elements contain the same pData, only the fist is removed. If none of the elements contain the pData, the BkList is unchanged
* \param link the link to remove from the BkList
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_EraseLink(struct BkList* link);

/*! \brief Prepends a new element on to the start of the list
*
* \param obj Any BkList element
* \param data The data for the new element
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_PushFront(struct BkList* obj, void* data);

/*! \brief Prepends a new element on to the end of the list
*
* \param obj Any BkList element
* \param data The data for the new element
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_PushBack(struct BkList* obj, void* data);

/*! \brief Remove the first element from a BkList
*
* \param obj Any BkList element
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_PopFront(struct BkList* obj);

/*! \brief Remove the last element from a BkList
*
* \param obj Any BkList element
* \return The start of the BkList
*/
extern BK_API struct BkList*	BkList_PopBack(struct BkList* obj);

/*! \brief Allocates space for one BkList element
*
* \return a pointer to the newly-allocated BkList element
*/
extern BK_API struct BkList*	BkList_Alloc(void);

#endif