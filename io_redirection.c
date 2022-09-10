#include "headers.h"
void io_redirect(char *string[], INT num_tokens, INT type_io[2], INT io_index[2], INT num_types)
{

    if (num_types == 2)
    {
        INT std_out = dup(1);
        INT std_in = dup(0);
        if (type_io[0] == 0)
        {
            if (io_index[0] != num_tokens - 1)
            {
                INT fd = open(string[io_index[0] + 1], O_RDONLY);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 0);
                    close(fd);
                    dup2(std_in, 0);
                    close(std_in);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is <,which is not valid");
                return;
            }
        }
        else if (type_io[0] == 1)
        {
            if (io_index[0] != num_tokens - 1)
            {
                INT fd = open(string[io_index[0] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 1);
                    close(fd);
                    dup2(std_out, 1);
                    close(std_out);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is >,which is not valid");
                return;
            }
        }
        else if (type_io[0] == 2)
        {
            if (io_index[0] != num_tokens - 1)
            {
                INT fd = open(string[io_index[0] + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 1);
                    close(fd);
                    dup2(std_out, 1);
                    close(std_out);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is >>,which is not valid");
                return;
            }
        }
        //
        std_out = dup(1);
        std_in = dup(0);
        if (type_io[1] == 0)
        {
            if (io_index[1] != num_tokens - 1)
            {
                INT fd = open(string[io_index[1] + 1], O_RDONLY);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 0);
                    close(fd);
                    dup2(std_in, 0);
                    close(std_in);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is <,which is not valid");
                return;
            }
        }
        else if (type_io[1] == 1)
        {
            if (io_index[1] != num_tokens - 1)
            {
                INT fd = open(string[io_index[1] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 1);
                    close(fd);
                    dup2(std_out, 1);
                    close(std_out);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is >,which is not valid");
                return;
            }
        }
        else if (type_io[1] == 2)
        {
            if (io_index[1] != num_tokens - 1)
            {
                INT fd = open(string[io_index[1] + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 1);
                    close(fd);
                    dup2(std_out, 1);
                    close(std_out);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is >>,which is not valid");
                return;
            }
        }
    }
    else if (num_types == 1)
    {
        INT std_out = dup(1);
        INT std_in = dup(0);
        if (type_io[0] == 0)
        {
            if (io_index[0] != num_tokens - 1)
            {
                INT fd = open(string[io_index[0] + 1], O_RDONLY);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 0);
                    close(fd);
                    dup2(std_in, 0);
                    close(std_in);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is <,which is not valid");
                return;
            }
        }
        else if (type_io[0] == 1)
        {
            if (io_index[0] != num_tokens - 1)
            {
                INT fd = open(string[io_index[0] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 1);
                    close(fd);
                    dup2(std_out, 1);
                    close(std_out);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is >,which is not valid");
                return;
            }
        }
        else if (type_io[0] == 2)
        {
            if (io_index[0] != num_tokens - 1)
            {
                INT fd = open(string[io_index[0] + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
                if (fd == -1)
                {
                    close(std_in);
                    close(std_out);
                    perror((NULL));
                    return;
                }
                else
                {
                    dup2(fd, 1);
                    close(fd);
                    dup2(std_out, 1);
                    close(std_out);
                }
            }
            else
            {
                close(std_in);
                close(std_out);
                perror("last token is >>,which is not valid");
                return;
            }
        }
    }
}
