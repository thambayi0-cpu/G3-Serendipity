/**
 * @file bookType.h
 * @brief Declaration of the bookType class for managing book inventory data.
 *
 * This class encapsulates bibliographic information, inventory quantity,
 * and pricing (wholesale/retail). Quantity is capped at 100, and pricing fields
 * are capped at 999.99. A static counter tracks the number of bookType
 * objects created.
 */

#ifndef BOOKTYPE_H
#define BOOKTYPE_H

#include <string>
#include <vector>

/**
 * @class bookType
 * @brief Stores metadata and inventory information for a book.
 *
 * Fields:
 *  - title: Book title
 *  - isbn: ISBN identifier
 *  - author: Author name
 *  - publisher: Publisher name
 *  - date: Date string (mm/dd/yy)
 *  - qty: Quantity in stock (capped at 100)
 *  - wholesale: Wholesale price (capped at 999.99)
 *  - retail: Retail price (capped at 999.99)
 *
 * A static field tracks the number of bookType objects created.
 */
class bookType
{
private:

    /** @brief Title of the book. */
    std::string title;

    /** @brief ISBN number of the book. */
    std::string isbn;

    /** @brief Author of the book. */
    std::string author;

    /** @brief Publisher of the book. */
    std::string publisher;

    /** @brief Date string in mm/dd/yy format. */
    std::string date;

    /** @brief Quantity in stock (0–100). */
    unsigned int qty;

    /** @brief Wholesale price (0.0–999.99). */
    float wholesale;

    /** @brief Retail price (0.0–999.99). */
    float retail;

public:

    /**
     * @brief Tracks how many bookType objects have been created.
     *
     * @note Must be maintained manually in constructor/destructor.
     */
    static unsigned int bookCount;

	bool operator<(const bookType& rhs) const;

    /* ===========================================
       Setters / Mutators
       =========================================== */

    /**
     * @brief Copy all fields from another bookType instance.
     * @param other The book whose values will be copied.
     *
     * @pre `other` is a valid bookType object.
     * @post All fields in this object match those of `other`.
     */
    void bookFill(const bookType& other);

    /**
     * @brief Reset all book fields to default "empty" values.
     *
     * @pre None.
     * @post
     *    - title == "EMPTY"
     *    - isbn == "EMPTY"
     *    - author == "EMPTY"
     *    - publisher == "EMPTY"
     *    - date == "EMPTY"
     *    - qty == 0
     *    - wholesale == 0.0f
     *    - retail == 0.0f
     */
    void bookEmpty();

    /**
     * @brief Set the title of the book.
     * @param t The title string.
     *
     * @pre None (non-empty recommended).
     * @post title == t.
     */
    void setTitle(std::string t);

    /**
     * @brief Set the ISBN.
     * @param i ISBN string.
     *
     * @pre None.
     * @post isbn == i.
     */
    void setIsbn(std::string i);

    /**
     * @brief Set the author name.
     * @param a Author string.
     *
     * @pre None (non-empty recommended).
     * @post author == a.
     */
    void setAuthor(std::string a);

    /**
     * @brief Set the publisher name.
     * @param p Publisher string.
     *
     * @pre None.
     * @post publisher == p.
     */
    void setPublisher(std::string p);

    /**
     * @brief Set the date.
     * @param d Date in mm/dd/yy format.
     *
     * @pre None (format validity recommended).
     * @post date == d.
     */
    void setDate(std::string d);

    /**
     * @brief Set the quantity (capped at 100).
     * @param q Quantity value.
     *
     * @pre q >= 0.
     * @post
     *    - If q <= 100, qty == q.
     *    - If q > 100, qty == 100.
     */
    void setQty(unsigned int q);

    /**
     * @brief Set the wholesale price (capped at 999.99).
     * @param w Wholesale price.
     *
     * @pre w >= 0.0f.
     * @post
     *    - If w <= 999.99, wholesale == w.
     *    - If w > 999.99, wholesale == 999.99.
     */
    void setWholesale(float w);

    /**
     * @brief Set the retail price (capped at 999.99).
     * @param r Retail price.
     *
     * @pre r >= 0.0f.
     * @post
     *    - If r <= 999.99, retail == r.
     *    - If r > 999.99, retail == 999.99.
     */
    void setRetail(float r);

    /* ===========================================
       Accessors / Getters
       =========================================== */

    /**
     * @brief Get the book title.
     * @return The title string.
     *
     * @pre None.
     * @post No modification to object state.
     */
    std::string getTitle() const;

    /**
     * @brief Get the ISBN.
     * @return The stored ISBN.
     *
     * @pre None.
     * @post No modification.
     */
    std::string getIsbn() const;

    /**
     * @brief Get the author.
     * @return The stored author string.
     *
     * @pre None.
     * @post No modification.
     */
    std::string getAuthor() const;

    /**
     * @brief Get the publisher.
     * @return Publisher string.
     *
     * @pre None.
     * @post No modification.
     */
    std::string getPublisher() const;

    /**
     * @brief Get the date.
     * @return Date string.
     *
     * @pre None.
     * @post No modification.
     */
    std::string getDate() const;

    /**
     * @brief Get the quantity.
     * @return Quantity value (0–100).
     *
     * @pre None.
     * @post No modification.
     */
    unsigned int getQty() const;

    /**
     * @brief Get the wholesale price.
     * @return Wholesale price (0.0–999.99).
     *
     * @pre None.
     * @post No modification.
     */
    float getWholesale() const;

    /**
     * @brief Get the retail price.
     * @return Retail price (0.0–999.99).
     *
     * @pre None.
     * @post No modification.
     */
    float getRetail() const;

    /* ===========================================
       Constructor / Destructor
       =========================================== */

    /**
     * @brief Construct a new bookType object.
     *
     * @param t Title (default: "EMPTY")
     * @param i ISBN (default: "EMPTY")
     * @param a Author (default: "EMPTY")
     * @param p Publisher (default: "EMPTY")
     * @param d Date (default: "EMPTY")
     * @param q Quantity (capped at 100; default: 0)
     * @param w Wholesale price (capped at 999.99; default: 0.0)
     * @param r Retail price (capped at 999.99; default: 0.0)
     *
     * @pre q >= 0, w >= 0.0, r >= 0.0.
     * @post
     *    - All fields initialized with provided values (subject to caps).
     *    - bookCount incremented.
     */
    bookType(std::string t = "EMPTY", std::string i = "EMPTY",
             std::string a = "EMPTY", std::string p = "EMPTY",
             std::string d = "EMPTY", unsigned int q = 0,
             float w = 0.0f, float r = 0.0f);

    /**
     * @brief Destructor for bookType.
     *
     * @pre None.
     * @post bookCount decremented (if implemented).
     */
    ~bookType();
};

#endif
