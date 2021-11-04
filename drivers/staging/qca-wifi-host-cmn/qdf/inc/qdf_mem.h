/*
<<<<<<< HEAD
 * Copyright (c) 2014-2017 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2014-2020 The Linux Foundation. All rights reserved.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/**
 * DOC: qdf_mem
 * QCA driver framework (QDF) memory management APIs
 */

#if !defined(__QDF_MEMORY_H)
#define __QDF_MEMORY_H

/* Include Files */
#include <qdf_types.h>
#include <i_qdf_mem.h>
<<<<<<< HEAD
=======
#include <i_qdf_trace.h>
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#define QDF_CACHE_LINE_SZ __qdf_cache_line_sz

/**
<<<<<<< HEAD
=======
 * qdf_align() - align to the given size.
 * @a: input that needs to be aligned.
 * @align_size: boundary on which 'a' has to be alinged.
 *
 * Return: aligned value.
 */
#define qdf_align(a, align_size)   __qdf_align(a, align_size)
#define qdf_page_size __page_size

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * struct qdf_mem_dma_page_t - Allocated dmaable page
 * @page_v_addr_start: Page start virtual address
 * @page_v_addr_end: Page end virtual address
 * @page_p_addr: Page start physical address
 */
struct qdf_mem_dma_page_t {
	char *page_v_addr_start;
	char *page_v_addr_end;
	qdf_dma_addr_t page_p_addr;
};

/**
 * struct qdf_mem_multi_page_t - multiple page allocation information storage
 * @num_element_per_page: Number of element in single page
 * @num_pages: Number of allocation needed pages
 * @dma_pages: page information storage in case of coherent memory
 * @cacheable_pages: page information storage in case of cacheable memory
<<<<<<< HEAD
=======
 * @is_mem_prealloc: flag for multiple pages pre-alloc or not
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
struct qdf_mem_multi_page_t {
	uint16_t num_element_per_page;
	uint16_t num_pages;
	struct qdf_mem_dma_page_t *dma_pages;
	void **cacheable_pages;
<<<<<<< HEAD
=======
	qdf_size_t page_size;
#ifdef DP_MEM_PRE_ALLOC
	uint8_t is_mem_prealloc;
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
};


/* Preprocessor definitions and constants */

typedef __qdf_mempool_t qdf_mempool_t;

/**
 * qdf_mem_init() - Initialize QDF memory module
 *
 * Return: None
 *
 */
void qdf_mem_init(void);

/**
 * qdf_mem_exit() - Exit QDF memory module
 *
 * Return: None
 *
 */
void qdf_mem_exit(void);

<<<<<<< HEAD
/**
 * struct qdf_mem_domain - memory domains for tracking memory allocations
 * @QDF_MEM_DOMAIN_INIT: The default memory domain
 * @QDF_MEM_DOMAIN_ACTIVE: The network interface active memory domain
 * @QDF_MEM_DOMAIN_MAX_COUNT: The number of memory domains for iterating, etc.
 */
enum qdf_mem_domain {
	QDF_MEM_DOMAIN_INIT,
	QDF_MEM_DOMAIN_ACTIVE,
	QDF_MEM_DOMAIN_MAX_COUNT,
};

/**
 * qdf_mem_get_domain() - Get the current memory domain
 *
 * Return: the current memory domain
 */
enum qdf_mem_domain qdf_mem_get_domain(void);

/**
 * qdf_mem_set_domain() - Set the current memory domain
 * @domain: the domain to change to
 *
 * This function changes the memory domain associated with future memory
 * allocations. This can be used to check for memory leaks when combined with
 * qdf_mem_check_for_leaks().
 *
 * Return: None
 */
void qdf_mem_set_domain(enum qdf_mem_domain domain);

/**
 * qdf_mem_domain_name() - Get the human readable name of a memory domain
 * @domain: The domain to return the name of
 *
 * Return: name of the given domain
 */
const uint8_t *qdf_mem_domain_name(enum qdf_mem_domain domain);

#ifdef MEMORY_DEBUG
/**
 * qdf_mem_malloc_debug() - debug version of QDF memory allocation API
 * @size: Number of bytes of memory to allocate.
 * @file: File name of the call site
 * @line: Line number of the call site
=======
#define QDF_MEM_FUNC_NAME_SIZE 48

#ifdef MEMORY_DEBUG
/**
 * qdf_mem_debug_config_get() - Get the user configuration of mem_debug_disabled
 *
 * Return: value of mem_debug_disabled qdf module argument
 */
bool qdf_mem_debug_config_get(void);

/**
 * qdf_mem_malloc_debug() - debug version of QDF memory allocation API
 * @size: Number of bytes of memory to allocate.
 * @func: Function name of the call site
 * @line: Line number of the call site
 * @caller: Address of the caller function
 * @flag: GFP flag
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This function will dynamicallly allocate the specified number of bytes of
 * memory and add it to the qdf tracking list to check for memory leaks and
 * corruptions
 *
 * Return: A valid memory location on success, or NULL on failure
 */
<<<<<<< HEAD
void *qdf_mem_malloc_debug(size_t size, const char *file, uint32_t line);

#define qdf_mem_malloc(size) \
	qdf_mem_malloc_debug(size, __FILE__, __LINE__)

=======
void *qdf_mem_malloc_debug(size_t size, const char *func, uint32_t line,
			   void *caller, uint32_t flag);

#define qdf_mem_malloc(size) \
	qdf_mem_malloc_debug(size, __func__, __LINE__, QDF_RET_IP, 0)

#define qdf_mem_malloc_fl(size, func, line) \
	qdf_mem_malloc_debug(size, func, line, QDF_RET_IP, 0)

#define qdf_mem_malloc_atomic(size) \
	qdf_mem_malloc_debug(size, __func__, __LINE__, QDF_RET_IP, GFP_ATOMIC)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * qdf_mem_free_debug() - debug version of qdf_mem_free
 * @ptr: Pointer to the starting address of the memory to be freed.
 *
<<<<<<< HEAD
 * Return: None
=======
 * This function will free the memory pointed to by 'ptr'. It also checks for
 * memory corruption, underrun, overrun, double free, domain mismatch, etc.
 *
 * Return: none
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
void qdf_mem_free_debug(void *ptr, const char *file, uint32_t line);

#define qdf_mem_free(ptr) \
<<<<<<< HEAD
	qdf_mem_free_debug(ptr, __FILE__, __LINE__)
=======
	qdf_mem_free_debug(ptr, __func__, __LINE__)

void qdf_mem_multi_pages_alloc_debug(qdf_device_t osdev,
				     struct qdf_mem_multi_page_t *pages,
				     size_t element_size, uint16_t element_num,
				     qdf_dma_context_t memctxt, bool cacheable,
				     const char *func, uint32_t line,
				     void *caller);

#define qdf_mem_multi_pages_alloc(osdev, pages, element_size, element_num,\
				  memctxt, cacheable) \
	qdf_mem_multi_pages_alloc_debug(osdev, pages, element_size, \
					element_num, memctxt, cacheable, \
					__func__, __LINE__, QDF_RET_IP)

void qdf_mem_multi_pages_free_debug(qdf_device_t osdev,
				    struct qdf_mem_multi_page_t *pages,
				    qdf_dma_context_t memctxt, bool cacheable,
				    const char *func, uint32_t line);

#define qdf_mem_multi_pages_free(osdev, pages, memctxt, cacheable) \
	qdf_mem_multi_pages_free_debug(osdev, pages, memctxt, cacheable, \
				       __func__, __LINE__)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * qdf_mem_check_for_leaks() - Assert that the current memory domain is empty
 *
 * Call this to ensure there are no active memory allocations being tracked
<<<<<<< HEAD
 * against the current memory domain. For example, one should call this function
 * immediately before a call to qdf_mem_set_domain() as a memory leak detection
 * mechanism.
 *
 * e.g.
 *	qdf_mem_set_domain(QDF_MEM_DOMAIN_ACTIVE);
=======
 * against the current debug domain. For example, one should call this function
 * immediately before a call to qdf_debug_domain_set() as a memory leak
 * detection mechanism.
 *
 * e.g.
 *	qdf_debug_domain_set(QDF_DEBUG_DOMAIN_ACTIVE);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 *	...
 *
 *	// memory is allocated and freed
 *
 *	...
 *
 *	// before transitioning back to inactive state,
 *	// make sure all active memory has been freed
 *	qdf_mem_check_for_leaks();
<<<<<<< HEAD
 *	qdf_mem_set_domain(QDF_MEM_DOMAIN_INIT);
 *
 *	...
 *
 *	// before program exit, make sure init time memory is freed
=======
 *	qdf_debug_domain_set(QDF_DEBUG_DOMAIN_INIT);
 *
 *	...
 *
 *	// also, before program exit, make sure init time memory is freed
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *	qdf_mem_check_for_leaks();
 *	exit();
 *
 * Return: None
 */
void qdf_mem_check_for_leaks(void);
<<<<<<< HEAD
#else
void *qdf_mem_malloc(qdf_size_t size);

/**
 * qdf_mem_free() - free QDF memory
 * @ptr: Pointer to the starting address of the memory to be free'd.
 *
 * Return: None
 */
void qdf_mem_free(void *ptr);

static inline void qdf_mem_check_for_leaks(void) { }
#endif /* MEMORY_DEBUG */

void *qdf_mem_alloc_outline(qdf_device_t osdev, qdf_size_t size);

void qdf_mem_set(void *ptr, uint32_t num_bytes, uint32_t value);

void qdf_mem_zero(void *ptr, uint32_t num_bytes);

void qdf_mem_copy(void *dst_addr, const void *src_addr, uint32_t num_bytes);

void qdf_mem_move(void *dst_addr, const void *src_addr, uint32_t num_bytes);

void qdf_mem_free_outline(void *buf);
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * qdf_mem_alloc_consistent_debug() - allocates consistent qdf memory
 * @osdev: OS device handle
 * @dev: Pointer to device handle
 * @size: Size to be allocated
 * @paddr: Physical address
<<<<<<< HEAD
 * @file: file name of the call site
 * @line: line numbe rof the call site
=======
 * @func: Function name of the call site
 * @line: line numbe rof the call site
 * @caller: Address of the caller function
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Return: pointer of allocated memory or null if memory alloc fails
 */
void *qdf_mem_alloc_consistent_debug(qdf_device_t osdev, void *dev,
<<<<<<< HEAD
				 qdf_size_t size, qdf_dma_addr_t *paddr,
				 const char *file, uint32_t line);

#define qdf_mem_alloc_consistent(osdev, dev, size, paddr) \
	qdf_mem_alloc_consistent_debug(osdev, dev, size, paddr, __FILE__, __LINE__)
=======
				     qdf_size_t size, qdf_dma_addr_t *paddr,
				     const char *func, uint32_t line,
				     void *caller);

#define qdf_mem_alloc_consistent(osdev, dev, size, paddr) \
	qdf_mem_alloc_consistent_debug(osdev, dev, size, paddr, \
				       __func__, __LINE__, QDF_RET_IP)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * qdf_mem_free_consistent_debug() - free consistent qdf memory
 * @osdev: OS device handle
 * @size: Size to be allocated
 * @vaddr: virtual address
 * @paddr: Physical address
 * @memctx: Pointer to DMA context
<<<<<<< HEAD
 * @file: file name of the call site
=======
 * @func: Function name of the call site
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @line: line numbe rof the call site
 *
 * Return: none
 */
void qdf_mem_free_consistent_debug(qdf_device_t osdev, void *dev,
<<<<<<< HEAD
			       qdf_size_t size, void *vaddr,
			       qdf_dma_addr_t paddr, qdf_dma_context_t memctx,
			       const char *file, uint32_t line);

#define qdf_mem_free_consistent(osdev, dev, size, vaddr, paddr, memctx) \
	qdf_mem_free_consistent_debug(osdev, dev, size, vaddr, paddr, memctx, \
				  __FILE__, __LINE__)

void qdf_mem_zero_outline(void *buf, qdf_size_t size);

/**
 * qdf_mem_cmp() - memory compare
 * @memory1: pointer to one location in memory to compare.
 * @memory2: pointer to second location in memory to compare.
 * @num_bytes: the number of bytes to compare.
 *
 * Function to compare two pieces of memory, similar to memcmp function
 * in standard C.
 * Return:
 * int32_t - returns an int value that tells if the memory
 * locations are equal or not equal.
 * 0 -- equal
 * < 0 -- *memory1 is less than *memory2
 * > 0 -- *memory1 is bigger than *memory2
 */
static inline int32_t qdf_mem_cmp(const void *memory1, const void *memory2,
				  uint32_t num_bytes)
{
	return __qdf_mem_cmp(memory1, memory2, num_bytes);
}

/**
 * qdf_str_cmp - Compare two strings
 * @str1: First string
 * @str2: Second string
 * Return: =0 equal
 * >0    not equal, if  str1  sorts lexicographically after str2
 * <0    not equal, if  str1  sorts lexicographically before str2
 */
static inline int32_t qdf_str_cmp(const char *str1, const char *str2)
{
	return __qdf_str_cmp(str1, str2);
}

/**
 * qdf_str_lcopy - Copy from one string to another
 * @dest: destination string
 * @src: source string
 * @bytes: limit of num bytes to copy
 * Return: =0 returns the initial value of dest
 */
static inline uint32_t qdf_str_lcopy(char *dest, const char *src, uint32_t bytes)
{
	return __qdf_str_lcopy(dest, src, bytes);
}

/**
=======
				   qdf_size_t size, void *vaddr,
				   qdf_dma_addr_t paddr,
				   qdf_dma_context_t memctx,
				   const char *func, uint32_t line);

#define qdf_mem_free_consistent(osdev, dev, size, vaddr, paddr, memctx) \
	qdf_mem_free_consistent_debug(osdev, dev, size, vaddr, paddr, memctx, \
				  __func__, __LINE__)
#else
static inline bool qdf_mem_debug_config_get(void)
{
	return false;
}

/**
 * qdf_mem_malloc() - allocation QDF memory
 * @size: Number of bytes of memory to allocate.
 *
 * This function will dynamicallly allocate the specified number of bytes of
 * memory.
 *
 * Return:
 * Upon successful allocate, returns a non-NULL pointer to the allocated
 * memory.  If this function is unable to allocate the amount of memory
 * specified (for any reason) it returns NULL.
 */
#define qdf_mem_malloc(size) \
	__qdf_mem_malloc(size, __func__, __LINE__)

#define qdf_mem_malloc_fl(size, func, line) \
	__qdf_mem_malloc(size, func, line)

/**
 * qdf_mem_malloc_atomic() - allocation QDF memory atomically
 * @size: Number of bytes of memory to allocate.
 *
 * This function will dynamicallly allocate the specified number of bytes of
 * memory.
 *
 * Return:
 * Upon successful allocate, returns a non-NULL pointer to the allocated
 * memory.  If this function is unable to allocate the amount of memory
 * specified (for any reason) it returns NULL.
 */
#define qdf_mem_malloc_atomic(size) \
	qdf_mem_malloc_atomic_fl(size, __func__, __LINE__)

void *qdf_mem_malloc_atomic_fl(qdf_size_t size,
			       const char *func,
			       uint32_t line);

#define qdf_mem_free(ptr) \
	__qdf_mem_free(ptr)

static inline void qdf_mem_check_for_leaks(void) { }

#define qdf_mem_alloc_consistent(osdev, dev, size, paddr) \
	__qdf_mem_alloc_consistent(osdev, dev, size, paddr, __func__, __LINE__)

#define qdf_mem_free_consistent(osdev, dev, size, vaddr, paddr, memctx) \
	__qdf_mem_free_consistent(osdev, dev, size, vaddr, paddr, memctx)

void qdf_mem_multi_pages_alloc(qdf_device_t osdev,
			       struct qdf_mem_multi_page_t *pages,
			       size_t element_size, uint16_t element_num,
			       qdf_dma_context_t memctxt, bool cacheable);

void qdf_mem_multi_pages_free(qdf_device_t osdev,
			      struct qdf_mem_multi_page_t *pages,
			      qdf_dma_context_t memctxt, bool cacheable);

#endif /* MEMORY_DEBUG */

/**
 * qdf_mem_multi_pages_zero() - zero out each page memory
 * @pages: Multi page information storage
 * @cacheable: Coherent memory or cacheable memory
 *
 * This function will zero out each page memory
 *
 * Return: None
 */
void qdf_mem_multi_pages_zero(struct qdf_mem_multi_page_t *pages,
			      bool cacheable);

/**
 * qdf_aligned_malloc() - allocates aligned QDF memory.
 * @size: Size to be allocated
 * @vaddr_unaligned: Unaligned virtual address.
 * @paddr_unaligned: Unaligned physical address.
 * @paddr_aligned: Aligned physical address.
 * @align: Base address alignment.
 * @func: Function name of the call site.
 * @line: Line number of the call site.
 *
 * This function will dynamically allocate the specified number of bytes of
 * memory. Checks if the allocated base address is aligned with base_align.
 * If not, it frees the allocated memory, adds base_align to alloc size and
 * re-allocates the memory.
 *
 * Return:
 * Upon successful allocate, returns an aligned base address of the allocated
 * memory.  If this function is unable to allocate the amount of memory
 * specified (for any reason) it returns NULL.
 */
#define qdf_aligned_malloc(size, vaddr_unaligned, paddr_unaligned, \
			   paddr_aligned, align) \
	qdf_aligned_malloc_fl(size, vaddr_unaligned, paddr_unaligned, \
			   paddr_aligned, align, __func__, __LINE__)

void *qdf_aligned_malloc_fl(uint32_t *size, void **vaddr_unaligned,
			    qdf_dma_addr_t *paddr_unaligned,
			    qdf_dma_addr_t *paddr_aligned,
			    uint32_t align,
			    const char *func, uint32_t line);

/**
 * qdf_aligned_mem_alloc_consistent() - allocates consistent qdf memory
 * @osdev: OS device handle
 * @size: Size to be allocated
 * @vaddr_unaligned: Unaligned virtual address.
 * @paddr_unaligned: Unaligned physical address.
 * @paddr_aligned: Aligned physical address.
 * @align: Base address alignment.
 * @func: Function name of the call site.
 * @line: Line number of the call site.
 *
 * Return: pointer of allocated memory or null if memory alloc fails.
 */
#define qdf_aligned_mem_alloc_consistent(osdev, size, vaddr_unaligned, \
					 paddr_unaligned, paddr_aligned, \
					 align) \
	qdf_aligned_mem_alloc_consistent_fl(osdev, size, vaddr_unaligned, \
					    paddr_unaligned, paddr_aligned, \
					    align, __func__, __LINE__)

void *qdf_aligned_mem_alloc_consistent_fl(qdf_device_t osdev, uint32_t *size,
					  void **vaddr_unaligned,
					  qdf_dma_addr_t *paddr_unaligned,
					  qdf_dma_addr_t *paddr_aligned,
					  uint32_t align, const char *func,
					  uint32_t line);

#define qdf_mem_virt_to_phys(vaddr) virt_to_phys(vaddr)

void qdf_mem_set_io(void *ptr, uint32_t num_bytes, uint32_t value);

void qdf_mem_copy_toio(void *dst_addr, const void *src_addr,
					   uint32_t num_bytes);

/**
 * qdf_mem_set() - set (fill) memory with a specified byte value.
 * @ptr: Pointer to memory that will be set
 * @num_bytes: Number of bytes to be set
 * @value: Byte set in memory
 *
 * WARNING: parameter @num_bytes and @value are swapped comparing with
 * standard C function "memset", please ensure correct usage of this function!
 *
 * Return: None
 */
void qdf_mem_set(void *ptr, uint32_t num_bytes, uint32_t value);

/**
 * qdf_mem_zero() - zero out memory
 * @ptr: pointer to memory that will be set to zero
 * @num_bytes: number of bytes zero
 *
 * This function sets the memory location to all zeros, essentially clearing
 * the memory.
 *
 * Return: None
 */
static inline void qdf_mem_zero(void *ptr, uint32_t num_bytes)
{
	qdf_mem_set(ptr, num_bytes, 0);
}

/**
 * qdf_mem_copy() - copy memory
 * @dst_addr: Pointer to destination memory location (to copy to)
 * @src_addr: Pointer to source memory location (to copy from)
 * @num_bytes: Number of bytes to copy.
 *
 * Copy host memory from one location to another, similar to memcpy in
 * standard C.  Note this function does not specifically handle overlapping
 * source and destination memory locations.  Calling this function with
 * overlapping source and destination memory locations will result in
 * unpredictable results.  Use qdf_mem_move() if the memory locations
 * for the source and destination are overlapping (or could be overlapping!)
 *
 * Return: none
 */
void qdf_mem_copy(void *dst_addr, const void *src_addr, uint32_t num_bytes);

/**
 * qdf_mem_move() - move memory
 * @dst_addr: pointer to destination memory location (to move to)
 * @src_addr: pointer to source memory location (to move from)
 * @num_bytes: number of bytes to move.
 *
 * Move host memory from one location to another, similar to memmove in
 * standard C.  Note this function *does* handle overlapping
 * source and destination memory locations.

 * Return: None
 */
void qdf_mem_move(void *dst_addr, const void *src_addr, uint32_t num_bytes);

/**
 * qdf_mem_cmp() - memory compare
 * @left: pointer to one location in memory to compare
 * @right: pointer to second location in memory to compare
 * @size: the number of bytes to compare
 *
 * Function to compare two pieces of memory, similar to memcmp function
 * in standard C.
 *
 * Return:
 *	0 -- equal
 *	< 0 -- *memory1 is less than *memory2
 *	> 0 -- *memory1 is bigger than *memory2
 */
int qdf_mem_cmp(const void *left, const void *right, size_t size);

void qdf_ether_addr_copy(void *dst_addr, const void *src_addr);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * qdf_mem_map_nbytes_single - Map memory for DMA
 * @osdev: pomter OS device context
 * @buf: pointer to memory to be dma mapped
 * @dir: DMA map direction
 * @nbytes: number of bytes to be mapped.
 * @phy_addr: ponter to recive physical address.
 *
 * Return: success/failure
 */
static inline uint32_t qdf_mem_map_nbytes_single(qdf_device_t osdev, void *buf,
						 qdf_dma_dir_t dir, int nbytes,
<<<<<<< HEAD
						 uint32_t *phy_addr)
{
#if defined(HIF_PCI)
=======
						 qdf_dma_addr_t *phy_addr)
{
#if defined(HIF_PCI) || defined(HIF_IPCI)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return __qdf_mem_map_nbytes_single(osdev, buf, dir, nbytes, phy_addr);
#else
	return 0;
#endif
}

<<<<<<< HEAD
=======
static inline void qdf_mem_dma_cache_sync(qdf_device_t osdev,
					  qdf_dma_addr_t buf,
					  qdf_dma_dir_t dir,
					  int nbytes)
{
	__qdf_mem_dma_cache_sync(osdev, buf, dir, nbytes);
}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * qdf_mem_unmap_nbytes_single() - un_map memory for DMA
 * @osdev: pomter OS device context
 * @phy_addr: physical address of memory to be dma unmapped
 * @dir: DMA unmap direction
 * @nbytes: number of bytes to be unmapped.
 *
 * Return: none
 */
static inline void qdf_mem_unmap_nbytes_single(qdf_device_t osdev,
<<<<<<< HEAD
					       uint32_t phy_addr,
					       qdf_dma_dir_t dir,
					       int nbytes)
{
#if defined(HIF_PCI)
=======
					       qdf_dma_addr_t phy_addr,
					       qdf_dma_dir_t dir,
					       int nbytes)
{
#if defined(HIF_PCI) || defined(HIF_IPCI)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	__qdf_mem_unmap_nbytes_single(osdev, phy_addr, dir, nbytes);
#endif
}

/**
 * qdf_mempool_init - Create and initialize memory pool
 * @osdev: platform device object
 * @pool_addr: address of the pool created
 * @elem_cnt: no. of elements in pool
 * @elem_size: size of each pool element in bytes
 * @flags: flags
 * Return: Handle to memory pool or NULL if allocation failed
 */
static inline int qdf_mempool_init(qdf_device_t osdev,
				   qdf_mempool_t *pool_addr, int elem_cnt,
				   size_t elem_size, uint32_t flags)
{
	return __qdf_mempool_init(osdev, pool_addr, elem_cnt, elem_size,
				  flags);
}

/**
 * qdf_mempool_destroy - Destroy memory pool
 * @osdev: platform device object
 * @Handle: to memory pool
 * Return: none
 */
static inline void qdf_mempool_destroy(qdf_device_t osdev, qdf_mempool_t pool)
{
	__qdf_mempool_destroy(osdev, pool);
}

/**
 * qdf_mempool_alloc - Allocate an element memory pool
 * @osdev: platform device object
 * @Handle: to memory pool
 * Return: Pointer to the allocated element or NULL if the pool is empty
 */
static inline void *qdf_mempool_alloc(qdf_device_t osdev, qdf_mempool_t pool)
{
	return (void *)__qdf_mempool_alloc(osdev, pool);
}

/**
 * qdf_mempool_free - Free a memory pool element
 * @osdev: Platform device object
 * @pool: Handle to memory pool
 * @buf: Element to be freed
 * Return: none
 */
static inline void qdf_mempool_free(qdf_device_t osdev, qdf_mempool_t pool,
				    void *buf)
{
	__qdf_mempool_free(osdev, pool, buf);
}

void qdf_mem_dma_sync_single_for_device(qdf_device_t osdev,
					qdf_dma_addr_t bus_addr,
					qdf_size_t size,
<<<<<<< HEAD
					qdf_dma_dir_t direction);
=======
					__dma_data_direction direction);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void qdf_mem_dma_sync_single_for_cpu(qdf_device_t osdev,
					qdf_dma_addr_t bus_addr,
					qdf_size_t size,
<<<<<<< HEAD
					qdf_dma_dir_t direction);
/**
 * qdf_str_len() - returns the length of a string
 * @str: input string
 * Return:
 * length of string
 */
static inline int32_t qdf_str_len(const char *str)
{
	return __qdf_str_len(str);
}

void qdf_mem_multi_pages_alloc(qdf_device_t osdev,
			       struct qdf_mem_multi_page_t *pages,
			       size_t element_size, uint16_t element_num,
			       qdf_dma_context_t memctxt, bool cacheable);
void qdf_mem_multi_pages_free(qdf_device_t osdev,
			      struct qdf_mem_multi_page_t *pages,
			      qdf_dma_context_t memctxt, bool cacheable);
=======
					__dma_data_direction direction);

int qdf_mem_multi_page_link(qdf_device_t osdev,
		struct qdf_mem_multi_page_t *pages,
		uint32_t elem_size, uint32_t elem_count, uint8_t cacheable);

#ifdef WLAN_DEBUGFS

/**
 * qdf_mem_kmalloc_inc() - increment kmalloc allocated bytes count
 * @size: number of bytes to increment by
 *
 * Return: None
 */
void qdf_mem_kmalloc_inc(qdf_size_t size);

/**
 * qdf_mem_kmalloc_dec() - decrement kmalloc allocated bytes count
 * @size: number of bytes to decrement by
 *
 * Return: None
 */
void qdf_mem_kmalloc_dec(qdf_size_t size);

#else

static inline void qdf_mem_kmalloc_inc(qdf_size_t size) { }
static inline void qdf_mem_kmalloc_dec(qdf_size_t size) { }

#endif /* WLAN_DEBUGFS */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * qdf_mem_skb_inc() - increment total skb allocation size
 * @size: size to be added
 *
 * Return: none
 */
void qdf_mem_skb_inc(qdf_size_t size);

/**
 * qdf_mem_skb_dec() - decrement total skb allocation size
 * @size: size to be decremented
 *
 * Return: none
 */
void qdf_mem_skb_dec(qdf_size_t size);

/**
 * qdf_mem_map_table_alloc() - Allocate shared memory info structure
 * @num: number of required storage
 *
 * Allocate mapping table for DMA memory allocation. This is needed for
 * IPA-WLAN buffer sharing when SMMU Stage1 Translation is enabled.
 *
 * Return: shared memory info storage table pointer
 */
static inline qdf_mem_info_t *qdf_mem_map_table_alloc(uint32_t num)
{
	qdf_mem_info_t *mem_info_arr;

<<<<<<< HEAD
	mem_info_arr = qdf_mem_malloc(num * sizeof(qdf_mem_info_t));
=======
	mem_info_arr = qdf_mem_malloc(num * sizeof(mem_info_arr[0]));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return mem_info_arr;
}

/**
 * qdf_update_mem_map_table() - Update DMA memory map info
 * @osdev: Parent device instance
 * @mem_info: Pointer to shared memory information
 * @dma_addr: dma address
 * @mem_size: memory size allocated
 *
 * Store DMA shared memory information
 *
 * Return: none
 */
static inline void qdf_update_mem_map_table(qdf_device_t osdev,
					    qdf_mem_info_t *mem_info,
					    qdf_dma_addr_t dma_addr,
					    uint32_t mem_size)
{
	if (!mem_info) {
<<<<<<< HEAD
		__qdf_print("%s: NULL mem_info\n", __func__);
		return;
	}

	mem_info->pa = __qdf_mem_paddr_from_dmaaddr(osdev, dma_addr);
	mem_info->iova = dma_addr;
	mem_info->size = mem_size;
=======
		qdf_nofl_err("%s: NULL mem_info", __func__);
		return;
	}

	__qdf_update_mem_map_table(osdev, mem_info, dma_addr, mem_size);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * qdf_mem_smmu_s1_enabled() - Return SMMU stage 1 translation enable status
 * @osdev parent device instance
 *
<<<<<<< HEAD
 * @Return: true if smmu s1 enabled, false if smmu s1 is bypassed
=======
 * Return: true if smmu s1 enabled, false if smmu s1 is bypassed
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline bool qdf_mem_smmu_s1_enabled(qdf_device_t osdev)
{
	return __qdf_mem_smmu_s1_enabled(osdev);
}

/**
 * qdf_mem_paddr_from_dmaaddr() - get actual physical address from dma address
 * @osdev: Parent device instance
 * @dma_addr: DMA/IOVA address
 *
 * Get actual physical address from dma_addr based on SMMU enablement status.
 * IF SMMU Stage 1 tranlation is enabled, DMA APIs return IO virtual address
 * (IOVA) otherwise returns physical address. So get SMMU physical address
 * mapping from IOVA.
 *
 * Return: dmaable physical address
 */
static inline qdf_dma_addr_t qdf_mem_paddr_from_dmaaddr(qdf_device_t osdev,
							qdf_dma_addr_t dma_addr)
{
	return __qdf_mem_paddr_from_dmaaddr(osdev, dma_addr);
}

/**
 * qdf_mem_dma_get_sgtable() - Returns DMA memory scatter gather table
 * @dev: device instace
 * @sgt: scatter gather table pointer
 * @cpu_addr: HLOS virtual address
 * @dma_addr: dma address
 * @size: allocated memory size
 *
<<<<<<< HEAD
 * @Return: status
=======
 * Return: physical address
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline int
qdf_mem_dma_get_sgtable(struct device *dev, void *sgt, void *cpu_addr,
			qdf_dma_addr_t dma_addr, size_t size)
{
	return __qdf_os_mem_dma_get_sgtable(dev, sgt, cpu_addr, dma_addr, size);
}

/**
 * qdf_mem_free_sgtable() - Free a previously allocated sg table
 * @sgt: the mapped sg table header
 *
<<<<<<< HEAD
 * @Return: None
=======
 * Return: None
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline void
qdf_mem_free_sgtable(struct sg_table *sgt)
{
	__qdf_os_mem_free_sgtable(sgt);
}

/**
 * qdf_dma_get_sgtable_dma_addr() - Assigns DMA address to scatterlist elements
 * @sgt: scatter gather table pointer
 *
<<<<<<< HEAD
 * @Return: None
=======
 * Return: None
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline void
qdf_dma_get_sgtable_dma_addr(struct sg_table *sgt)
{
<<<<<<< HEAD
	return __qdf_dma_get_sgtable_dma_addr(sgt);
=======
	__qdf_dma_get_sgtable_dma_addr(sgt);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * qdf_mem_get_dma_addr() - Return dma address based on SMMU translation status.
 * @osdev: Parent device instance
 * @mem_info: Pointer to allocated memory information
 *
 * Get dma address based on SMMU enablement status. If SMMU Stage 1
 * tranlation is enabled, DMA APIs return IO virtual address otherwise
 * returns physical address.
 *
<<<<<<< HEAD
 * @Return: dma address
=======
 * Return: dma address
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline qdf_dma_addr_t qdf_mem_get_dma_addr(qdf_device_t osdev,
						  qdf_mem_info_t *mem_info)
{
	return __qdf_mem_get_dma_addr(osdev, mem_info);
}

/**
 * qdf_mem_get_dma_addr_ptr() - Return DMA address pointer from mem info struct
 * @osdev: Parent device instance
 * @mem_info: Pointer to allocated memory information
 *
 * Based on smmu stage 1 translation enablement, return corresponding dma
 * address storage pointer.
 *
<<<<<<< HEAD
 * @Return: dma address storage pointer
=======
 * Return: dma address storage pointer
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline qdf_dma_addr_t *qdf_mem_get_dma_addr_ptr(qdf_device_t osdev,
						       qdf_mem_info_t *mem_info)
{
	return __qdf_mem_get_dma_addr_ptr(osdev, mem_info);
}

<<<<<<< HEAD
/**
 * qdf_mem_shared_mem_alloc() - Allocate DMA memory for shared resource
 * @osdev: parent device instance
 * @mem_info: Pointer to allocated memory information
 * @size: size to be allocated
 *
 * Allocate DMA memory which will be shared with external kernel module. This
 * information is needed for SMMU mapping.
 *
 * @Return: 0 suceess
 */
static inline qdf_shared_mem_t *qdf_mem_shared_mem_alloc(qdf_device_t osdev,
							 uint32_t size)
{
	qdf_shared_mem_t *shared_mem;
	int ret;

	shared_mem = qdf_mem_malloc(sizeof(qdf_shared_mem_t));
	if (!shared_mem) {
		__qdf_print("%s: Unable to allocate memory for shared resource struct\n",
			    __func__);
		return NULL;
	}

	shared_mem->vaddr = qdf_mem_alloc_consistent(osdev, osdev->dev, size,
				(qdf_dma_addr_t *)&shared_mem->mem_info.iova);
	if (!shared_mem->vaddr) {
		__qdf_print("%s; Unable to allocate DMA memory for shared resource\n",
			    __func__);
		qdf_mem_free(shared_mem);
		return NULL;
	}

	shared_mem->mem_info.size = size;
	qdf_mem_zero(shared_mem->vaddr, shared_mem->mem_info.size);
	shared_mem->mem_info.pa = __qdf_mem_paddr_from_dmaaddr(osdev,
				    (qdf_dma_addr_t)shared_mem->mem_info.iova);
	ret = qdf_mem_dma_get_sgtable(osdev->dev,
				(void *)&shared_mem->sgtable,
				shared_mem->vaddr,
				qdf_mem_get_dma_addr(osdev,
						     &shared_mem->mem_info),
				shared_mem->mem_info.size);
	if (ret) {
		__qdf_print("%s; Unable to get DMA sgtable\n", __func__);
		qdf_mem_free_consistent(osdev, osdev->dev,
					shared_mem->mem_info.size,
					shared_mem->vaddr,
					qdf_mem_get_dma_addr(osdev,
						&shared_mem->mem_info),
					qdf_get_dma_mem_context(shared_mem,
								memctx));
		qdf_mem_free(shared_mem);
		return NULL;
	}

	qdf_dma_get_sgtable_dma_addr(&shared_mem->sgtable);

	return shared_mem;
}

/**
=======

/**
 * qdf_mem_get_dma_size() - Return DMA memory size
 * @osdev: parent device instance
 * @mem_info: Pointer to allocated memory information
 *
 * Return: DMA memory size
 */
static inline uint32_t
qdf_mem_get_dma_size(qdf_device_t osdev,
		       qdf_mem_info_t *mem_info)
{
	return __qdf_mem_get_dma_size(osdev, mem_info);
}

/**
 * qdf_mem_set_dma_size() - Set DMA memory size
 * @osdev: parent device instance
 * @mem_info: Pointer to allocated memory information
 * @mem_size: memory size allocated
 *
 * Return: none
 */
static inline void
qdf_mem_set_dma_size(qdf_device_t osdev,
		       qdf_mem_info_t *mem_info,
		       uint32_t mem_size)
{
	__qdf_mem_set_dma_size(osdev, mem_info, mem_size);
}

/**
 * qdf_mem_get_dma_size() - Return DMA physical address
 * @osdev: parent device instance
 * @mem_info: Pointer to allocated memory information
 *
 * Return: DMA physical address
 */
static inline qdf_dma_addr_t
qdf_mem_get_dma_pa(qdf_device_t osdev,
		     qdf_mem_info_t *mem_info)
{
	return __qdf_mem_get_dma_pa(osdev, mem_info);
}

/**
 * qdf_mem_set_dma_size() - Set DMA physical address
 * @osdev: parent device instance
 * @mem_info: Pointer to allocated memory information
 * @dma_pa: DMA phsical address
 *
 * Return: none
 */
static inline void
qdf_mem_set_dma_pa(qdf_device_t osdev,
		     qdf_mem_info_t *mem_info,
		     qdf_dma_addr_t dma_pa)
{
	__qdf_mem_set_dma_pa(osdev, mem_info, dma_pa);
}

/**
 * qdf_mem_shared_mem_alloc() - Allocate DMA memory for shared resource
 * @osdev: parent device instance
 * @mem_info: Pointer to allocated memory information
 * @size: size to be allocated
 *
 * Allocate DMA memory which will be shared with external kernel module. This
 * information is needed for SMMU mapping.
 *
 * Return: 0 success
 */
qdf_shared_mem_t *qdf_mem_shared_mem_alloc(qdf_device_t osdev, uint32_t size);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * qdf_mem_shared_mem_free() - Free shared memory
 * @osdev: parent device instance
 * @shared_mem: shared memory information storage
 *
 * Free DMA shared memory resource
 *
<<<<<<< HEAD
 * @Return: None
=======
 * Return: None
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline void qdf_mem_shared_mem_free(qdf_device_t osdev,
					   qdf_shared_mem_t *shared_mem)
{
	if (!shared_mem) {
<<<<<<< HEAD
		__qdf_print("%s: NULL shared mem struct passed\n",
			    __func__);
=======
		qdf_nofl_err("%s: NULL shared mem struct passed",
			     __func__);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	if (shared_mem->vaddr) {
		qdf_mem_free_consistent(osdev, osdev->dev,
<<<<<<< HEAD
					shared_mem->mem_info.size,
=======
					qdf_mem_get_dma_size(osdev,
						&shared_mem->mem_info),
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					shared_mem->vaddr,
					qdf_mem_get_dma_addr(osdev,
						&shared_mem->mem_info),
					qdf_get_dma_mem_context(shared_mem,
								memctx));
	}
<<<<<<< HEAD
	qdf_mem_free_sgtable(&(shared_mem->sgtable));
=======
	qdf_mem_free_sgtable(&shared_mem->sgtable);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	qdf_mem_free(shared_mem);
}

#endif /* __QDF_MEMORY_H */
