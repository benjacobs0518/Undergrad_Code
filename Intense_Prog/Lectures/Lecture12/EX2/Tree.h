#ifndef TREE_H
#define TREE_H

class Tree {
    public:
      static int count;

        Tree(){count+=1;}

        bool operator==(Tree &other);

        virtual void Seed() { number_seeds_ += 1; };

        int get_number_seeds() { return number_seeds_; }

    private:
        static int number_seeds_;
};

class Sapling : public Tree{
public:
    void Seed(){
    Tree::Seed();
    Tree::Seed();
    };

};

#endif // TREE_H
